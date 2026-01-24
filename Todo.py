# To-Do List Application

def show_menu():
    print("\nOptions:")
    print("1. View tasks")
    print("2. Add a task")
    print("3. Remove a task")
    print("4. Mark a task as completed")
    print("5. Exit")

def view_tasks(tasks):
    if len(tasks) == 0:
        print("\nNo tasks to show!")
    else:
        print("\nTo-Do List:")
        for idx, task in enumerate(tasks):
            status = "✔" if task['completed'] else "✘"
            print(f"{idx + 1}. {task['task']} [{status}]")

def add_task(tasks):
    task = input("\nEnter the task: ")
    tasks.append({'task': task, 'completed': False})
    print(f"Task '{task}' added.")

def remove_task(tasks):
    view_tasks(tasks)
    try:
        task_num = int(input("\nEnter the task number to remove: ")) - 1
        removed_task = tasks.pop(task_num)
        print(f"Task '{removed_task['task']}' removed.")
    except (IndexError, ValueError):
        print("Invalid task number.")

def complete_task(tasks):
    view_tasks(tasks)
    try:
        task_num = int(input("\nEnter the task number to mark as completed: ")) - 1
        tasks[task_num]['completed'] = True
        print(f"Task '{tasks[task_num]['task']}' marked as completed.")
    except (IndexError, ValueError):
        print("Invalid task number.")

def main():
    tasks = []
    while True:
        show_menu()
        choice = input("\nEnter your choice: ")
        
        if choice == "1":
            view_tasks(tasks)
        elif choice == "2":
            add_task(tasks)
        elif choice == "3":
            remove_task(tasks)
        elif choice == "4":
            complete_task(tasks)
        elif choice == "5":
            print("Goodbye!")
            break
        else:
            print("Invalid choice! Please try again.")

if __name__ == "__main__":
    main()
