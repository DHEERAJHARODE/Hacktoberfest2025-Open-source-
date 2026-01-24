class TaskQueue {
  constructor(concurrency) {
    this.concurrency = concurrency;
    this.queue = [];
    this.activeCount = 0;
  }

  async runTask(task) {
    this.activeCount++;
    try {
      await task();  // Execute the task
    } finally {
      this.activeCount--;
      this.next();  // Run the next task in queue if possible
    }
  }

  next() {
    if (this.queue.length > 0 && this.activeCount < this.concurrency) {
      const { task, resolve, reject } = this.queue.shift();
      this.runTask(task).then(resolve).catch(reject);
    }
  }

  add(task) {
    return new Promise((resolve, reject) => {
      this.queue.push({ task, resolve, reject });
      this.next();  // Try to run the next task when a new one is added
    });
  }
}

// Example usage:
const queue = new TaskQueue(3);  // Limit concurrency to 3

function createTask(taskNum) {
  return () => new Promise((resolve) => {
    console.log(`Starting task ${taskNum}`);
    setTimeout(() => {
      console.log(`Completed task ${taskNum}`);
      resolve();
    }, 1000 + Math.random() * 2000); // Simulate variable-length async tasks
  });
}

// Add multiple tasks to the queue
for (let i = 1; i <= 10; i++) {
  queue.add(createTask(i));
}
