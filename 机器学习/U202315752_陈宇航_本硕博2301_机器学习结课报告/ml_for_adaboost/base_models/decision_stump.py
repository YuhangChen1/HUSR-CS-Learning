# cpu
import numpy as np
import logging

logger = logging.getLogger(__name__)

class DecisionStump:
    def __init__(self):
        self.feature_idx = None
        self.threshold = None
        self.polarity = 1

    def fit(self, X, y, sample_weight=None):
        n_samples, n_features = X.shape
        if sample_weight is None:
            sample_weight = np.ones(n_samples) / n_samples

        min_error = float('inf')

        for f in range(n_features):
            feature_values = X[:, f]
            unique_vals = np.unique(feature_values)

            for threshold in unique_vals:
                p = 1
                preds = np.ones(n_samples, dtype=int)
                preds[feature_values < threshold] = -1
                mis = (preds != y)
                error = np.sum(sample_weight[mis])

                if error > 0.5:
                    error = 1 - error
                    p = -1

                if error < min_error:
                    min_error = error
                    self.feature_idx = f
                    self.threshold = threshold
                    self.polarity = p

        logger.debug(f"DecisionStump 最优特征={self.feature_idx}, threshold={self.threshold}, polarity={self.polarity}, min_error={min_error:.4f}")

    def predict(self, X):
        n_samples = X.shape[0]
        preds = np.ones(n_samples, dtype=int)
        preds[X[:, self.feature_idx] < self.threshold] = -1
        return preds * self.polarity


# gpu
# import torch
# import logging

# logger = logging.getLogger(__name__)

# class DecisionStump:
#     def __init__(self, device='cuda'):
#         self.feature_idx = None
#         self.threshold = None
#         self.polarity = 1
#         self.device = device  # This stores the device (cpu or cuda)

#     def fit(self, X, y, sample_weight=None):
#         X, y = X.to(self.device), y.to(self.device)  # Move data to the appropriate device
#         n_samples, n_features = X.shape
#         if sample_weight is None:
#             sample_weight = torch.ones(n_samples, device=self.device) / n_samples  # Make sure sample_weight is on the correct device

#         min_error = float('inf')

#         for f in range(n_features):
#             feature_values = X[:, f]
#             unique_vals = torch.unique(feature_values)

#             for threshold in unique_vals:
#                 p = 1
#                 preds = torch.ones(n_samples, dtype=torch.int, device=self.device)
#                 preds[feature_values < threshold] = -1
#                 mis = (preds != y)
#                 error = torch.sum(sample_weight[mis])

#                 if error > 0.5:
#                     error = 1 - error
#                     p = -1

#                 if error < min_error:
#                     min_error = error
#                     self.feature_idx = f
#                     self.threshold = threshold
#                     self.polarity = p

#         logger.debug(f"DecisionStump 最优特征={self.feature_idx}, threshold={self.threshold}, polarity={self.polarity}, min_error={min_error:.4f}")

#     def predict(self, X):
#         X = X.to(self.device)  # Make sure input data is on the correct device
#         n_samples = X.shape[0]
#         preds = torch.ones(n_samples, dtype=torch.int, device=self.device)
#         preds[X[:, self.feature_idx] < self.threshold] = -1
#         return preds * self.polarity
