class Node:
    """"
    An object for storing a single node of a linked list
    models two attributs -> data and the link to the next node in the list 
    """
    data = None
    next_node = None

    def __init__(self,data) :
        self.data=data

    def __repr__(self) :
        return "<Node data: %s>" % self.data
        
        
class Linked_list:

    def __init__(self) :
        self.head = None

    def is_empty(self):
        return self.head == None

    def size (self):
        current = self.head
        count=0

        while current:
            count +=1
            current = current.next_node
        return count

    def add(self,data):
        
         new_node = Node(data)
         new_node.next_node = self.head
         self.head = new_node
