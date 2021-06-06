# -*- coding: utf-8 -*-
"""
Spyder Editor

This is a temporary script file.
"""

class Graph():
    def __init__(self, vertices):
        self.graph = [[0 for coloumn in range(vertices)]
                      for row in range(vertices)]
        self.V=vertices
        
    def check(self, v, pos, path):
        if self.graph[ path[pos-1] ][v]==0:
            return False
        for vertex in path:
            if vertex == v:
                return False
        return True
    def Hamiltonian_Cycle(self, path, pos):
        if pos==self.V:
            if self.graph[path[pos-1]][path[0]]==1:
                return True
            else:
                False
        for v in range(1,self.V):
            if self.check(v, pos, path)==True:
                path[pos]=v
                if self.Hamiltonian_Cycle(path, pos+1)==True:
                    return True
                path[pos]=-1
        return False
    def Ham_Cycle(self):
        path=[-1]*self.V
        path[0]=0
        if self.Hamiltonian_Cycle(path,1)==False:
            print("Hamiltonian Cycle does not exist\n")
            return False
        self.printSolution(path)
        return True
    def printSolution(self, path):
        print("Hamiltonian Cycle Exist")
        for vertex in path:
            print(vertex, end=" ")
        print(path[0],"\n")
g1=Graph(5)
g1.graph=[ [0, 1, 0, 1, 0], [1, 0, 1, 1, 1],  
            [0, 1, 0, 0, 1,],[1, 0, 1, 1, 1],  
            [0, 1, 1, 1, 0], ]  
g1.Ham_Cycle();  
g2 = Graph(5)  
g2.graph = [ [0, 1, 0, 1, 0], [1, 0, 0, 0, 0],  
        [0, 1, 0, 0, 1,], [1, 1, 0, 0, 0],  
        [0, 1, 1, 0, 0], ]  
g2.Ham_Cycle();  
  
