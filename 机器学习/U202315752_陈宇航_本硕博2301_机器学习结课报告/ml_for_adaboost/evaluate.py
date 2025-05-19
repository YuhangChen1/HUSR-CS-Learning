import numpy as np
import os
import logging
import datetime

if not os.path.exists("eva_log"):
    os.makedirs("eva_log")

current_time = datetime.datetime.now().strftime("%Y%m%d_%H%M%S")
log_filename = f"adaboost_evaluate_result_{current_time}.log"
log_filepath = os.path.join("eva_log", log_filename)

logging.basicConfig(
    level=logging.INFO,
    format="%(asctime)s [%(levelname)s] %(name)s:%(lineno)d - %(message)s",
    datefmt="%Y-%m-%d %H:%M:%S",
    filename=log_filepath,
    filemode="w"
)
logger = logging.getLogger(__name__)

target = np.genfromtxt('targets.csv')

base_list = [1, 5, 10, 100]

for base_num in base_list:
    acc = [] 
    for i in range(1, 11):
        fold = np.genfromtxt('experiments/base%d_fold%d.csv' % (base_num, i), delimiter=',', dtype=np.int64)
        accuracy = sum(target[fold[:, 0] - 1] == fold[:, 1]) / fold.shape[0]
        acc.append(accuracy)

    
    logger.info(np.array(acc).mean())
    print(np.array(acc).mean())
