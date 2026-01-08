![PRs Welcome](https://img.shields.io/badge/PRs-welcome-brightgreen.svg)
[![Slack Status](https://img.shields.io/badge/slack-join_chat-white.svg?logo=slack&style=social)](https://join.slack.com/t/osdfs/shared_invite/zt-eecws9vb-zvmzBeSPgBZrE9RWVj43Sw)

- Join osDFS on Slack and then search for `#c-algorithms`

# C-Algorithms
Our open source community is focussed on understanding the concepts and while doing so, whenever someone gets trapped, they can see one way to code in any language they want. So, we are developing a repository having implementation in as many languages as we can. But for now we are focused only on C languages. Soon we will work on another language as well.

## All Algorithms implemented in C (for learning)
Contribute algorithms written in C language. It's beginner friendly! Feel free to work on an open an issue and commit if you have a more efficient way of implementing an algorithm. You can!

## Getting Started
- **Fork** this repository (Click the 'Fork' button, top right of this page)
- **Clone** your forked copy of this repo down to your local machine:
```
git clone https://github.com/<insert-your-username>/C-Algorithms.git
```
- **Change directory** to get inside repository:
```
cd C-Algorithms
```
- **Create a branch** for a new algorithm contribution:
```
git checkout -b feature/<name-of-algorithm>
```
- *Or* if its a bugfix to a file:
```
git checkout -b bugfix/<title-of-issue>
```
- Make your changes locally
- **Stage** and **commit** changes:
```
git add .
git commit -m 'commit message'
```
- **Push** changes to GitHub:
```
git push origin <branch-name>
```
- Create a **New Pull Request** (PR) from your forked repository on GitHub (Click the 'New Pull Request' Button located at the top of your repo)
- Wait for your PR review and merge approval!
- ***Star this repository*** if you had fun! :)

### Sync it :recycle:

Always keep your local copy of repository updated with the original repository.
Before making any changes and/or in an appropriate interval, run the following commands *carefully* to update your local repository.

```sh
# Fetch all remote repositories and delete any deleted remote branches
$ git fetch --all --prune

# Switch to `master` branch
$ git checkout master

# Reset local `master` branch to match `upstream` repository's `master` branch
$ git reset --hard upstream/master

# Push changes to your forked `Algo_Ds_Notes` repo
$ git push origin master
```

### Create a new branch ‼️
Whenever you are going to make contribution. Please create seperate branch using command and keep your master branch clean (i.e. synced with remote branch).

# It will create a new branch with name Branch_Name and switch to branch Folder_Name
```
$ git checkout -b Folder_Name
```
Create a seperate branch for contibution and try to use same name of branch as of folder.

To switch to desired branch

# To switch from one folder to other
```
$ git checkout Folder_Name
```
To add the changes to the branch. Use

# To add all files to branch Folder_Name
```
$ git add .
```
Type in a message relevant for the code reveiwer using

# This message get associated with all files you have changed
```
$ git commit -m 'relevant message'
```
Now, Push your awesome work to your remote repository using

# To push your work to your remote repository
```
$ git push -u origin Folder_Name
```
Finally, go to your repository in browser and click on compare and pull requests. Then add a title and description to your pull request that explains your precious effort.
  
## New to Open Source?
Check out the following resources:
- [How to Create a Pull Request](https://www.digitalocean.com/community/tutorials/how-to-create-a-pull-request-on-github)
- [An Introduction to Open Source](https://www.digitalocean.com/community/tutorial_series/an-introduction-to-open-source)
 
## What to contribute?
- You can check the [Issues](https://github.com/TeAmp0is0N/C-Algorithms/issues) tab on the top and comment on the one you want to work on.
- You can also suggest addition of new algorithms. Just create an 'Issue' [here](https://github.com/TeAmp0is0N/C-Algorithms/issues).
- You can also contribute your solutions to problems from LeetCode: [LeetCode](https://leetcode.com/problemset/algorithms/)
  - Place your code in '/LeetCodeSolutions' folder with *number* and *name* of the problem as the file name. 
- You can also contribute your solutions to problems from Project Euler: [Project Euler](https://projecteuler.net/archives)
  - Place your code in '/ProjectEulerSolutions' folder with *number* and *name* of the problem as the file name.

### References :clipboard: :scroll:

- Books :book: :books:
    - Data Structures with C by Schaum Series
    - Data Structures: A Pseudocode Approach with C by Richard F. Gilberg
    - Fundamentals Of Data Structures in C by Horowitz
    - Introduction To Algorithms By Thomas H. Cormen
    - Computer Oriented Numerical Methods By V. Rajaraman 
- Websites :computer:
    - [GeeksforGeeks](http://www.geeksforgeeks.org)
    - [hackerearth](https://www.hackerearth.com/notes)
    - [topcoder](https://www.topcoder.com/community/data-science/data-science-tutorials)
    - [tutorialspoint](http://www.tutorialspoint.com)
    - [Wikipedia](https://en.wikipedia.org)
