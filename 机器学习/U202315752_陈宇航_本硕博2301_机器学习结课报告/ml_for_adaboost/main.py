#cpu
import sys
import numpy as np
import os
import logging
import datetime

from utils.data_loader import load_data
from utils.cross_validation import k_fold_split
from adaboost.adaboost import AdaBoost
from base_models.logistic_regression import LogisticRegressionModel
from base_models.decision_stump import DecisionStump

# 日志配置
if not os.path.exists("log"):
    os.makedirs("log")

current_time = datetime.datetime.now().strftime("%Y%m%d_%H%M%S")
log_filename = f"adaboost_training_{current_time}.log"
log_filepath = os.path.join("log", log_filename)

logging.basicConfig(
    level=logging.INFO,
    format="%(asctime)s [%(levelname)s] %(name)s:%(lineno)d - %(message)s",
    datefmt="%Y-%m-%d %H:%M:%S",
    filename=log_filepath,
    filemode="w"
)
logger = logging.getLogger(__name__)


def main():
    if len(sys.argv) < 2:
        logger.error("未指定基分类器编号，退出程序。")
        sys.exit(1)

    base_classifier_id = int(sys.argv[1])
    logger.info(f"基分类器编号: {base_classifier_id}")

    if base_classifier_id == 0:
        base_classifier_name = "LogisticRegression"
    elif base_classifier_id == 1:
        base_classifier_name = "DecisionStump"
    else:
        logger.error("基分类器编号错误，必须是0或1，退出程序。")
        sys.exit(1)

    if len(sys.argv) == 3:
        new_data_file = sys.argv[2]
        logger.info(f"使用基分类器: {base_classifier_name}, 对新测试数据文件 {new_data_file} 进行预测")

        X_train_full, y_train_full = load_data('data.csv', 'targets.csv')
        
        # Apply feature scaling to training data if Logistic Regression is the base classifier
        if base_classifier_id == 0:
            logger.info("Applying feature scaling for Logistic Regression on full training data.")
            mean_full = np.mean(X_train_full, axis=0)
            std_full = np.std(X_train_full, axis=0)
            std_full[std_full == 0] = 1e-8 # Avoid division by zero
            X_train_full = (X_train_full - mean_full) / std_full

        ada = AdaBoost(get_base_model=LogisticRegressionModel if base_classifier_id == 0 else DecisionStump,
                       n_estimators=10) # Note: n_estimators is fixed to 10 for new data prediction
        ada.fit(X_train_full, y_train_full)

        X_new = np.genfromtxt(new_data_file, delimiter=',', skip_header=0)
        # Apply the SAME scaling to new_data if Logistic Regression is the base classifier
        if base_classifier_id == 0:
            logger.info("Applying learned feature scaling to new data for Logistic Regression.")
            X_new = (X_new - mean_full) / std_full # Use mean_full and std_full from training data

        preds = ada.predict(X_new)

        for i, p in enumerate(preds, start=1):
            print(f"样本{i} 的预测标记 = {p}")

        logger.info(f"完成对新数据 {new_data_file} 的预测，共预测 {len(preds)} 条记录。")
    else:
        logger.info(f"使用基分类器: {base_classifier_name} 进行10折交叉验证，并输出到 experiments/ 文件夹")

        X, y = load_data('data.csv', 'targets.csv')
        folds = k_fold_split(X, y, k=10, shuffle=True, random_seed=2025)
        base_nums = [1, 5, 10, 100]

        if not os.path.exists('experiments'):
            os.makedirs('experiments')

        for base_num in base_nums:
            # Overall accuracy for this base_num across folds - not strictly needed for output files but good for logging
            # fold_accuracies = [] 
            for i in range(10):
                X_train_fold, y_train_fold, X_test_fold, y_test_fold, test_indices = folds[i]

                # Apply feature scaling within the cross-validation loop if Logistic Regression
                if base_classifier_id == 0:
                    mean_fold = np.mean(X_train_fold, axis=0)
                    std_fold = np.std(X_train_fold, axis=0)
                    std_fold[std_fold == 0] = 1e-8 # Avoid division by zero
                    
                    X_train_scaled = (X_train_fold - mean_fold) / std_fold
                    X_test_scaled = (X_test_fold - mean_fold) / std_fold # Apply same transformation to test
                else:
                    X_train_scaled = X_train_fold
                    X_test_scaled = X_test_fold

                ada = AdaBoost(get_base_model=LogisticRegressionModel if base_classifier_id == 0 else DecisionStump,
                               n_estimators=base_num)
                ada.fit(X_train_scaled, y_train_fold)
                preds = ada.predict(X_test_scaled)

                output_path = f"experiments/base{base_num}_fold{i + 1}.csv"
                with open(output_path, 'w') as fw:
                    for idx_in_data, pred_label in zip(test_indices, preds):
                        fw.write(f"{idx_in_data + 1},{int(pred_label)}\n")

            logger.info(f"完成基分类器数目={base_num} 的10折输出")
        logger.info("所有折次训练完成，10折交叉验证结果已输出到 experiments/ 文件夹")
        print("10 折交叉验证输出完成！可运行 evaluate.py 查看精度。")


if __name__ == "__main__":
    main()



# gpu
# import sys
# import torch
# import logging
# import datetime
# from utils.data_loader import load_data
# from utils.cross_validation import k_fold_split
# from adaboost.adaboost import AdaBoost
# from base_models.logistic_regression import LogisticRegressionModel
# from base_models.decision_stump import DecisionStump
# import os
# import numpy as np

# if not torch.cuda.is_available():
#     print("错误：GPU 不可用，程序将退出。")
#     sys.exit(1)  # 退出程序
# device = 'cuda' if torch.cuda.is_available() else 'cpu'

# # 日志配置
# if not os.path.exists("log"):
#     os.makedirs("log")

# current_time = datetime.datetime.now().strftime("%Y%m%d_%H%M%S")
# log_filename = f"adaboost_training_{current_time}.log"
# log_filepath = os.path.join("log", log_filename)

# logging.basicConfig(
#     level=logging.INFO,
#     format="%(asctime)s [%(levelname)s] %(name)s:%(lineno)d - %(message)s",
#     datefmt="%Y-%m-%d %H:%M:%S",
#     filename=log_filepath,
#     filemode="w"
# )
# logger = logging.getLogger(__name__)

# def main():
#     if len(sys.argv) < 2:
#         logger.error("未指定基分类器编号，退出程序。")
#         sys.exit(1)

#     base_classifier_id = int(sys.argv[1])
#     logger.info(f"基分类器编号: {base_classifier_id}")

#     if base_classifier_id == 0:
#         base_classifier_name = "LogisticRegression"
#     elif base_classifier_id == 1:
#         base_classifier_name = "DecisionStump"
#     else:
#         logger.error("基分类器编号错误，必须是0或1，退出程序。")
#         sys.exit(1)

#     if len(sys.argv) == 3:
#         new_data_file = sys.argv[2]
#         logger.info(f"使用基分类器: {base_classifier_name}, 对新测试数据文件 {new_data_file} 进行预测")

#         X, y = load_data('data.csv', 'targets.csv')
#         ada = AdaBoost(get_base_model=LogisticRegressionModel if base_classifier_id == 0 else DecisionStump,
#                        n_estimators=10, device=device)
#         ada.fit(X, y)

#         X_new = torch.tensor(np.genfromtxt(new_data_file, delimiter=',', skip_header=0), dtype=torch.float32, device=device)
#         preds = ada.predict(X_new)

#         for i, p in enumerate(preds, start=1):
#             print(f"样本{i} 的预测标记 = {p}")

#         logger.info(f"完成对新数据 {new_data_file} 的预测，共预测 {len(preds)} 条记录。")
#     else:
#         logger.info(f"使用基分类器: {base_classifier_name} 进行10折交叉验证，并输出到 experiments/ 文件夹")

#         X, y = load_data('data.csv', 'targets.csv')
#         folds = k_fold_split(X, y, k=10, shuffle=True, random_seed=2025)
#         base_nums = [1, 5, 10, 100]

#         if not os.path.exists('experiments'):
#             os.makedirs('experiments')

#         for base_num in base_nums:
#             for i in range(10):
#                 X_train, y_train, X_test, y_test, test_indices = folds[i]
#                 ada = AdaBoost(get_base_model=LogisticRegressionModel if base_classifier_id == 0 else DecisionStump,
#                                n_estimators=base_num, device=device)
#                 ada.fit(X_train, y_train)
#                 preds = ada.predict(X_test)

#                 output_path = f"experiments/base{base_num}_fold{i + 1}.csv"
#                 with open(output_path, 'w') as fw:
#                     for idx_in_data, pred_label in zip(test_indices, preds):
#                         fw.write(f"{idx_in_data + 1},{int(pred_label)}\n")

#             logger.info(f"完成基分类器数目={base_num} 的10折输出")
#         logger.info("所有折次训练完成，10折交叉验证结果已输出到 experiments/ 文件夹")
#         print("10 折交叉验证输出完成！可运行 evaluate.py 查看精度。")

# if __name__ == "__main__":
#     main()
