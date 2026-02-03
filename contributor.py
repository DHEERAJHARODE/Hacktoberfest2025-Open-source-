import requests

# Replace with the repository owner and repository name
owner = 'octocat'
repo = 'Hello-World'

# Optional: GitHub personal access token for authentication
# If you don't want to use it, leave `auth=None`
token = 'your_github_token_here'
auth = (token, '') if token else None

# GitHub API endpoint for repository contributors
url = f'https://api.github.com/repos/{owner}/{repo}/contributors'

def get_highest_contributor():
    try:
        # Send GET request to GitHub API
        response = requests.get(url, auth=auth)
        
        # Check if the request was successful
        if response.status_code == 200:
            contributors = response.json()
            
            # Check if contributors exist
            if not contributors:
                print("No contributors found for this repository.")
                return

            # Find the highest contributor by the number of contributions
            highest_contributor = max(contributors, key=lambda x: x['contributions'])

            # Print the highest contributor's information
            print(f"Highest contributor: {highest_contributor['login']}")
            print(f"Contributions: {highest_contributor['contributions']}")
            print(f"Profile: {highest_contributor['html_url']}")

        else:
            print(f"Failed to retrieve contributors. Status code: {response.status_code}")
            print(f"Response: {response.text}")

    except Exception as e:
        print(f"An error occurred: {e}")

# Run the function
get_highest_contributor()
