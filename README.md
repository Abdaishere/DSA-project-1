# DSA-project-1
	1) Login: type “username” to be logged in 
	2) Logout: type “logout” 
	3) Exit: type “exit”
	4) Application actions
		○ Login
		○ Exit
	5) List of all action logged in user can do 
		○ List all friends 
		○ Search by username 
		○ Add friend 
		○ Remove friend 
		○ People you may know
		○ logout
Logged in user Actions Description:
	● List all friends
		○ Traverse “friendsBST” of the logged in user
		○ Print these information for each friend in the tree
Username1, name1
Username2, name2
Username3, name3

	● Search by username
		○ If the username belongs to the friend list, display the user “name”.
		○ Otherwise display the not found message

Enter “usernameX”
If exist, print
UsernameX, nameX, email
If doesn’t exist, print
“not found”

	● Add friend
		○ if userA become friend with userB this mean userB also become friend with
		userA so you need to update the two users friendsBST

Enter “usernameX”
Print
You are now friendsIf they are already friends then print
You are already friends

	● Remove friend
		○ if userA remove userB from his friends this mean userA will be removed from
		userB friends so you need to update the two users friendsBST

Enter “usernameX”
Print
Done
If they are already not friends then do nothing

	● people you may know
		○ List any users not in user friend list
		○ Recommend 5 new friends - if the existed less than 5 view them -

Username1, name1
Username2, name2
Username3, name3