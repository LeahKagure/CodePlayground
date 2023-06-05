# Given a set of jobs with their deadlines and their profits, find the maximum profit that can be earned
# by scheduling the jobs without missing any deadlines

class Job:
    def __init__(self, id, deadline, profit):
        self.id = id
        self.deadline = deadline
        self.profit = profit

def job_sequencing(jobs):
    max_deadline = max(jobs, key=lambda x: x.deadline).deadline

    sequence = [' '] * max_deadline

    for job in jobs:
        for j in range(job.deadline - 1, -1, -1):
            if sequence[j] == ' ':
                sequence[j] = job.id
                break

    total_profit = 0
    print("Job sequence:", end=" ")
    for job_id in sequence:
        if job_id != ' ':
            print(job_id, end=" ")
            job = next((job for job in jobs if job.id == job_id), None)
            total_profit += job.profit
    print()
    print("Total profit:", total_profit)

jobs = [Job('a', 2, 100), Job('b', 1, 19), Job('c', 2, 27), Job('d', 1, 25), Job('e', 3, 15)]
job_sequencing(jobs)
