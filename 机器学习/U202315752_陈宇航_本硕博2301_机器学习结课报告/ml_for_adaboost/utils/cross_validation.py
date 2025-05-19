import numpy as np
import logging

logger = logging.getLogger(__name__)

def k_fold_split(X, y, k=10, shuffle=True, random_seed=2025):
    n_samples = X.shape[0]
    indices = np.arange(n_samples)
    if shuffle:
        np.random.seed(random_seed)
        np.random.shuffle(indices)

    fold_size = n_samples // k
    folds = []
    for i in range(k):
        start = i * fold_size
        end = n_samples if i == k-1 else start + fold_size

        test_idx = indices[start:end]
        train_idx = np.concatenate((indices[:start], indices[end:]))

        X_train, y_train = X[train_idx], y[train_idx]
        X_test, y_test = X[test_idx], y[test_idx]
        folds.append((X_train, y_train, X_test, y_test, test_idx))

    logger.info(f"k_fold_split: 已拆分为 {k} 折, each fold size~{fold_size} (最后一折={n_samples - fold_size*(k-1)})")
    return folds

