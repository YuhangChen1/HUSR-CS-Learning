#cpu版本
import numpy as np
import logging

logger = logging.getLogger(__name__)

def load_data(data_file, target_file):
    X = np.genfromtxt(data_file, delimiter=',', skip_header=0)
    y = np.genfromtxt(target_file, delimiter=',', skip_header=0)
    logger.info(f"load_data: 读取 {data_file} 和 {target_file}, 样本数={X.shape[0]}, 特征数={X.shape[1]}")
    return X, y

#gpu版本
# import torch
# import logging
# import numpy as np

# logger = logging.getLogger(__name__)

# def load_data(data_file, target_file):
#     X = torch.tensor(np.genfromtxt(data_file, delimiter=',', skip_header=0), dtype=torch.float32)
#     y = torch.tensor(np.genfromtxt(target_file, delimiter=',', skip_header=0), dtype=torch.float32)
#     logger.info(f"load_data: 读取 {data_file} 和 {target_file}, 样本数={X.shape[0]}, 特征数={X.shape[1]}")
#     return X, y
