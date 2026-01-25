
from datetime import datetime
import pandas as pd

# Define the structure of the to-do list
todo_list = {
    "Task": [
        "Review project requirements",
        "Update test cases for new feature",
        "Perform regression testing",
        "Prepare test reports",
        "Team meeting",
        "Follow up on bug fixes"
    ],
    "Priority": [
        "High",
        "Medium",
        "High",
        "Medium",
        "Low",
        "High"
    ],
    "Due Date": [
        "2024-10-01",
        "2024-10-02",
        "2024-10-03",
        "2024-10-04",
        "2024-10-05",
        "2024-10-06"
    ],
    "Status": [
        "Not Started",
        "In Progress",
        "Not Started",
        "Not Started",
        "Scheduled",
        "Not Started"
    ]
}

# Convert the dictionary to a DataFrame
todo_df = pd.DataFrame(todo_list)

# Convert "Due Date" to datetime format
todo_df["Due Date"] = pd.to_datetime(todo_df["Due Date"])

# Display the to-do list
print(todo_df)
