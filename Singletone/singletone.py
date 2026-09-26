import threading
import time

class Logger:
    _instance = None
    _lock = threading.Lock()
    _write_lock = threading.Lock()

    def __new__(cls):
        with cls._lock:
            if cls._instance is None:
                cls._instance = super().__new__(cls)
        return cls._instance

    def log(self, message : str):
        with self._write_lock:
            print(f"[LOG]: {message}")

def worker(thread_id : int, logger : Logger):
    logger.log(f"Thread {thread_id} is starting...")
    time.sleep(0.1)
    logger.log(f"Thread {thread_id} is starting...")

logger_instance = Logger()

threads = []
for i in range(4):
    t = threading.Thread(target=worker, args=(i, logger_instance))
    threads.append(t)
    t.start()

for t in threads:
    t.join()

print("All threads finished execution.")
print("="*30)

s1 = Logger()
s2 = Logger()

print(s1 is s2) # True
print(id(s1) == id(s2)) # True
print(hex(id(s1)), hex(id(s2))) # The same addresses

