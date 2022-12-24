<h3>Inventory Management System</h3>
This is an individual project for a programming fundamentals course, in which you are required to build an inventory management system for a college. The system should be able to perform the following functionality:

Add inventory items<br>
View all inventory items<br>
Search inventory items<br>
Edit inventory items (including item count)<br>
Delete inventory items<br>
Assign inventory items to faculty members<br>
Retrieve inventory items from faculty members<br>
View the list of faculty members who have borrowed a specific item<br>
An inventory item will be represented by a structure called InventoryItem, which has the following attributes:<br>

Name<br>
Item ID<br>
Category<br>
Item count<br>
Allocated to (an array containing the names of faculty members who have borrowed the item)<br>
The system should store and retrieve inventory items from a file named inventory_item_data.txt. Bonus marks will be given for implementing a graphical user interface (GUI) for the system.

To keep the system simple, the Allocated_to array for each inventory item will contain only the names of the faculty members who have borrowed the item. However, bonus credit will be given to students who use structures instead of just names in the Allocated_to array.

When an item is assigned to a faculty member, their name (or additional information) is added to the Allocated_to array, and the item count for that specific item is decreased by one. When an inventory item is retrieved, the information of the faculty member is removed from the Allocated_to array and the item count is increased by one.


