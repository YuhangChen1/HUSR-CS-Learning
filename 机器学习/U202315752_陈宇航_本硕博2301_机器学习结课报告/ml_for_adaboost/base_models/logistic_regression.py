#cpu
import numpy as np
import logging

logger = logging.getLogger(__name__)


def sigmoid(x):
    max_value = 500
    min_value = -500
    x = np.clip(x, min_value, max_value)  
    return 1.0 / (1.0 + np.exp(-x))
class LogisticRegressionModel:
    def __init__(self, lr=0.00707, max_iter=850, reg_strength=0.01):
        self.lr = lr
        self.max_iter = max_iter
        self.reg_strength = reg_strength  
        self.weights = None
        self.bias = 0

    def fit(self, X, y, sample_weight=None):
        n_samples, n_features = X.shape

        if sample_weight is None:
            sample_weight = np.ones(n_samples)

        self.weights = np.random.randn(n_features) * 0.01
        self.bias = 0.0

        for it in range(self.max_iter):
            linear_output = X.dot(self.weights) + self.bias
            # sigmoid
            probs = sigmoid(linear_output)

       
            y_01 = (y == 1).astype(float)

            diff = (probs - y_01)
            grad_w = X.T.dot(diff * sample_weight) + self.reg_strength * self.weights  
            grad_b = np.sum(diff * sample_weight)

            self.weights -= self.lr * grad_w
            self.bias -= self.lr * grad_b

            if it % 10 == 0:
                loss = -np.sum(sample_weight * (y_01 * np.log(probs + 1e-10) + (1 - y_01) * np.log(1 - probs + 1e-10))) \
                       + self.reg_strength * np.sum(self.weights ** 2)  
                logger.debug(f"[Iteration {it}] LogisticRegression loss={loss:.4f}")
            if it% (self.max_iter-1) == 0:
                logger.info(f",max_iter={self.max_iter}, learning_rate = {self.lr}")



    def predict(self, X):
        linear_output = X.dot(self.weights) + self.bias
        probs = sigmoid(linear_output)
        return np.where(probs >= 0.5, 1, -1)

# gpu
# import torch
# import logging

# logger = logging.getLogger(__name__)

# def sigmoid(x):
#     return 1.0 / (1.0 + torch.exp(-x))

# class LogisticRegressionModel:
#     def __init__(self, lr=0.00707, max_iter=300, reg_strength=0.01, device='cuda'):
#         self.lr = lr
#         self.max_iter = max_iter
#         self.reg_strength = reg_strength
#         self.device = device
#         self.weights = None
#         self.bias = torch.tensor(0.0, device=device)

#     def fit(self, X, y, sample_weight=None):
#         X, y = X.to(self.device), y.to(self.device)
#         n_samples, n_features = X.shape
#         if sample_weight is None:
#             sample_weight = torch.ones(n_samples, device=self.device)

#         self.weights = torch.randn(n_features, device=self.device) * 0.01

#         for it in range(self.max_iter):
#             linear_output = torch.matmul(X, self.weights) + self.bias
#             probs = sigmoid(linear_output)

#             y_01 = (y == 1).float()

#             diff = (probs - y_01)
#             grad_w = torch.matmul(X.T, diff * sample_weight) + self.reg_strength * self.weights
#             grad_b = torch.sum(diff * sample_weight)

#             self.weights -= self.lr * grad_w
#             self.bias -= self.lr * grad_b

#             if it % 10 == 0:
#                 loss = -torch.sum(sample_weight * (y_01 * torch.log(probs + 1e-10) + (1 - y_01) * torch.log(1 - probs + 1e-10))) \
#                        + self.reg_strength * torch.sum(self.weights ** 2)
#                 logger.debug(f"[Iteration {it}] LogisticRegression loss={loss:.4f}")

#             if it % (self.max_iter-1) == 0:
#                 logger.info(f",max_iter={self.max_iter}, learning_rate = {self.lr}")

#     def predict(self, X):
#         X = X.to(self.device)
#         linear_output = torch.matmul(X, self.weights) + self.bias
#         probs = sigmoid(linear_output)
#         return torch.where(probs >= 0.5, torch.tensor(1, device=self.device), torch.tensor(-1, device=self.device))
