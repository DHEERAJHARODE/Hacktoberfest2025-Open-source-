# Git Cheat Sheet

- git code .                                //Open vs code

- git status                                //Show file status 

- git status -s                             //show short file status

- git add <filename>                        //Add the particular file to staging area
  
- git add .                                  //Add all the file to the staging area
  
- git commit --amend                        //Add these changes to the last commit (will have to use vim editor)
  
- git commit -m "message"                   //Commit the files in the staging area    
  
- git commit -am "message"                  //Will commit without adding the file to the staging area
  
- git checkout --<filename>                 //will restore the file from the last commit
  
- git checkout -f                           //All the files will be replaced with last commit
  
- git checkout -b <branch name> 		   	  //Create a branch
  
- git branch 								//To see the branches
  
- git branch -d <branch name>				//To delete a branch
  
- git branch -v 							//will show the branch and its last commit
  
- git branch --merged 					//will show the branches that are merged
  
- git branch --no-merged 					//will show the branches that are not merged
  
- git merge <branch name>					//while in a branch you can merge another branch
  
- git log                                   //Show all the commits
  
- git log -n                                //n can be replaced by any number "will show last n commits"
  
- git log -p                                //Will show detailed discription of the commits  
  
- git log -p -n                             //use of n is similar as described above  
  
- git log --stat                            //will show short detailing of the commits  
  
- git log --stat -n                         //use of n is similar as described above    
  
- git log --since=n.days                    //commit of last n days/weeks/months "days can be replaced by weeks,months"
  
- git rm --cached <filename>                //will remove to file from the tracking area 
  
- git rm -rf                                //will uninitialized the current repository       
  
- git rm <filename>                         //will delete the file  
  
- git mv <Present filename> <The filename after the change>  //to Rename the file
  
- git clone <URL>                           //Cloning a repository in the current folder
  
- git clone <URL> foldername                //Cloning the repository in the given folder name (Folder will be created by itself) 
  
- git config --global alias. <new name> 'old command'  //while create an alias command for the given command
  
- git remote 						//Show all the name of remote repository
  
- git remote -v 					//Show all the path (fetch/push) of the remote repository
  
- git remote add <name> url			//Add a remote repository
  
- git remote rm <name>				//To remove a remote
  
- git push <remote name> <branch name>	//To push a branch to remote repository
  
- git push <remote name> <branch name>:<branch name you want to have in the remote repository>
  
- git reset HEAD						//To move to a previous commit


  
  
<br>
  
>More commands can be found on this website
//website https://git-scm.com/docs/git-log
  
 #### ***This Repo is contributed by [Pankaj Yadav](https://github.com/pankajpkpj)***
  
  @github.com/pankajpkpj
