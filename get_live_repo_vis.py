import requests

# Replace with your GitHub token
GITHUB_TOKEN = 'your_github_token'

# Repository details (owner/repo)
OWNER = 'repository_owner'  # e.g., 'octocat'
REPO = 'repository_name'    # e.g., 'Hello-World'

def get_repo_watchers(owner, repo, token):
    url = f"https://api.github.com/repos/{owner}/{repo}"
    headers = {
        'Authorization': f'token {token}'
    }
    response = requests.get(url, headers=headers)

    if response.status_code == 200:
        data = response.json()
        return data['subscribers_count']  # 'subscribers_count' gives the number of watchers
    else:
        print(f"Error: {response.status_code} - {response.json().get('message', '')}")
        return None

if __name__ == "__main__":
    watchers_count = get_repo_watchers(OWNER, REPO, GITHUB_TOKEN)
    if watchers_count is not None:
        print(f"Number of watchers for {OWNER}/{REPO}: {watchers_count}")
