import threading, time

empty = threading.Semaphore(5)    # free slots
full  = threading.Semaphore(0)    # jobs waiting
lock  = threading.Semaphore(1)    # one at a time
buffer = []                       # the waiting list

def producer():                   # the apps
    for i in range(1, 11):        # 10 jobs
        empty.acquire()           # wait(empty): need a free slot
        lock.acquire()            # wait(lock): lock the list
        buffer.append(i)
        print("Added job", i, "-> list:", buffer)
        lock.release()            # signal(lock): unlock the list
        full.release()            # signal(full): one more job is waiting
        time.sleep(0.5)           # producer is fast

def consumer():                   # the printer
    for i in range(1, 11):
        full.acquire()            # wait(full): need a job
        lock.acquire()            # wait(lock)
        job = buffer.pop(0)       # take the oldest job
        print("Printed job", job, "-> list:", buffer)
        lock.release()            # signal(lock)
        empty.release()           # signal(empty): one more free slot
        time.sleep(1)             # printer is slow

p = threading.Thread(target=producer)
c = threading.Thread(target=consumer)
p.start()
c.start()
p.join()
c.join()
