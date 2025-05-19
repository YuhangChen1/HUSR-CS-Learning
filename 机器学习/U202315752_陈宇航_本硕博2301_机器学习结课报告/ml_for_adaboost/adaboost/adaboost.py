#cpu
import numpy as np
import logging

logger = logging.getLogger(__name__)

class AdaBoost:
    def __init__(self, get_base_model, n_estimators=10, learning_rate=1.01075):
        # 新增 learning_rate 参数
        self.get_base_model = get_base_model
        self.n_estimators = n_estimators
        self.learning_rate = learning_rate  # 保存学习率参数
        self.models = []
        self.alphas = []

    def fit(self, X, y):
        y_ = np.where(y == 0, -1, 1).astype(float)  # 将标签从 [0, 1] 转换为 [-1, 1]
        n_samples = X.shape[0]
        w = np.ones(n_samples) / n_samples  # 初始化样本权重
        self.models = []
        self.alphas = []

        for t in range(self.n_estimators):
            model = self.get_base_model()  # 获取基分类器
            logger.info(f"model is {model}")
            model.fit(X, y_, sample_weight=w)  # 训练基分类器
            pred = model.predict(X)  # 预测结果
            mis = (pred != y_)  # 错误样本
            error_t = np.sum(w * mis)  # 计算错误率

            eps = 1e-10
            # 计算 alpha_t，并乘以学习率
            alpha_t = 0.5 * np.log((1.0 - error_t + eps) / (error_t + eps)) * self.learning_rate

            w *= np.exp(-alpha_t * y_ * pred)  # 更新样本权重
            w /= np.sum(w)  # 权重归一化

            self.models.append(model)  # 保存基分类器
            self.alphas.append(alpha_t)  # 保存基分类器的权重

            logger.debug(f"第 {t+1}/{self.n_estimators} 个基分类器: error_t={error_t:.4f}, alpha_t={alpha_t:.4f},lr ={self.learning_rate}")  # 仅打印前5个权重

    def predict(self, X):
        preds_weighted = []
        for model, alpha in zip(self.models, self.alphas):
            preds_weighted.append(model.predict(X) * alpha)  # 基分类器加权
        sum_preds = np.sum(preds_weighted, axis=0)  # 加权预测结果
        final_sign = np.sign(sum_preds)  # 取符号
        final_label = np.where(final_sign == -1, 0, 1)  # 转换回 [0, 1]
        return final_label

#gpu
# import torch
# import logging

# logger = logging.getLogger(__name__)

# class AdaBoost:
#     def __init__(self, get_base_model, n_estimators=10, learning_rate=0.4, device='cuda'):
#         self.get_base_model = get_base_model
#         self.n_estimators = n_estimators
#         self.learning_rate = learning_rate
#         self.device = device
#         self.models = []
#         self.alphas = []

#     def fit(self, X, y):
#         X, y = X.to(self.device), y.to(self.device)  # 确保数据在正确的设备上
#         y_ = torch.where(y == 0, torch.tensor(-1, device=self.device), torch.tensor(1, device=self.device)).float()
#         n_samples = X.shape[0]
#         w = torch.ones(n_samples, device=self.device) / n_samples
#         self.models = []
#         self.alphas = []

#         for t in range(self.n_estimators):
#             model = self.get_base_model()  # 获取基分类器
#             # 这里不再尝试将 model 移到 GPU
#             model.fit(X, y_, sample_weight=w)  # 训练基分类器
#             pred = model.predict(X)  # 预测结果
#             mis = (pred != y_)  # 错误样本
#             error_t = torch.sum(w * mis)  # 计算错误率

#             eps = 1e-10
#             # 计算 alpha_t，并乘以学习率
#             alpha_t = 0.5 * torch.log((1.0 - error_t + eps) / (error_t + eps)) * self.learning_rate

#             w *= torch.exp(-alpha_t * y_ * pred)  # 更新样本权重
#             w /= torch.sum(w)  # 权重归一化

#             self.models.append(model)  # 保存基分类器
#             self.alphas.append(alpha_t)  # 保存基分类器的权重

#             logger.debug(f"第 {t+1}/{self.n_estimators} 个基分类器: error_t={error_t:.4f}, alpha_t={alpha_t:.4f}, lr={self.learning_rate}")  # 仅打印前5个权重

#     def predict(self, X):
#         X = X.to(self.device)  # 确保输入数据在正确的设备上
#         preds_weighted = []
#         for model, alpha in zip(self.models, self.alphas):
#             preds_weighted.append(model.predict(X) * alpha)  # 基分类器加权
#         sum_preds = torch.sum(torch.stack(preds_weighted), dim=0)  # 加权预测结果
#         final_sign = torch.sign(sum_preds)  # 取符号
#         final_label = torch.where(final_sign == -1, torch.tensor(0, device=self.device), torch.tensor(1, device=self.device))  # 转换回 [0, 1]
#         return final_label

