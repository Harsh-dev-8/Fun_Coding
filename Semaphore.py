import threading, time

printers = threading.Semaphore(3)
print(printers)

def job(id):
    printers.acquire()
    print("job",id, "is printing")
    time.sleep(5)
    print("job", id, "done")
    printers.release()

threads = []

for i in range(1,5):
    t = threading.Thread(target=job, args=(i,))
    t.start()
    threads.append(t)

for t in threads:
    t.join()
print(threads)
