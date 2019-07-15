""" Node is defined as
class node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None
"""
def maxData(root):
    max_data = root.data
    if root.left:
        max_data = max(max_data,maxData(root.left))
    if root.right:
        max_data = max(max_data,maxData(root.right))
    return max_data

def minData(root):
    min_data = root.data
    if root.left:
        min_data = min(min_data,minData(root.left))
    if root.right:
        min_data = min(min_data,minData(root.right))
    return min_data
      
def checkBST(root):
    if root.left and maxData(root.left) >= root.data :
        return False
    if root.right and minData(root.right) <= root.data :
        return False
    if root.left and not checkBST(root.left) :
        return False
    if root.right and not checkBST(root.right) :
        return False
    return True

