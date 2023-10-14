#include "../Application.h"
#ifdef PRIM

#include <iostream>
#include "../Graph/Graph.h"
#include "../Graph/Node.h"
#include "Prim.h"

int main()
{
	//Initialize time
	srand(time(NULL));
	//Create a graph
	Graph* graph = new Graph();
	//Create our MST graph
	Graph* mst = new Graph();

	int choice;
	do
	{
		//Print the UI
		cout << endl;
		cout << "---Prim Interface---" << endl;
		cout << "1) Use Tutorial Graph" << endl;
		cout << "2) Use Lecture Graph" << endl;
		cout << "3) Randomly Generate Graph" << endl;
		cout << "4) Load Graph" << endl;
		cout << "5) Export Graph" << endl;
		cout << "6) Print Graph Details" << endl;
		cout << "7) Print MST Details" << endl;
		cout << "8) Build MST" << endl;
		cout << "9) Clear Console" << endl;
		cout << "10) Quit" << endl;
		cout << "Input choice: ";
		cin >> choice;

		switch (choice)
		{
			//Tutorial Graph
		case 1:
		{
			//Set the number of vertices to be 5
			graph->SetNoOfVertices(5);
			//Tutorial graph for it's adjacency matrix
			graph->adjMatrix = { { 0,4,2,6,8 },
								 { M,0,M,4,3 },
								 { M,M,0,1,M },
								 { M,1,M,0,3 },
								 { M,M,M,M,0 } };

			//Make many nodes for now to test (not the best implementation, just testing it out)
			Node* s = new Node(0, 0, "1");
			Node* u = new Node(1, 0, "2");
			Node* x = new Node(2, 0, "3");
			Node* v = new Node(3, 0, "4");
			Node* y = new Node(4, 0, "5");

			//Add into our graph the above nodes, storing the vertex as keys (assumes no vertex are repeated)
			graph->nodes[s->GetVertex()] = s;
			graph->nodes[u->GetVertex()] = u;
			graph->nodes[x->GetVertex()] = x;
			graph->nodes[v->GetVertex()] = v;
			graph->nodes[y->GetVertex()] = y;

			//Update adjacency list
			graph->UpdateAdjacencyList();
			//Get input and update adj matrix
			graph->PrintAdjMatrix();
			graph->PrintAdjList();
			break;
		}
		//lecture graph
		case 2:
		{
			//Set the number of vertices to be 5
			graph->SetNoOfVertices(14);

			//Manually add the edges
			graph->AddBidirectionalEdge(1, 2, 8);
			graph->AddBidirectionalEdge(1, 3, 4);
			graph->AddBidirectionalEdge(1, 4, 2);
			graph->AddBidirectionalEdge(2, 5, 9);
			graph->AddBidirectionalEdge(2, 13, 5);
			graph->AddBidirectionalEdge(3, 6, 9);
			graph->AddBidirectionalEdge(4, 5, 8);
			graph->AddBidirectionalEdge(4, 8, 1);
			graph->AddBidirectionalEdge(5, 7, 2);
			graph->AddBidirectionalEdge(6, 8, 2);
			graph->AddBidirectionalEdge(6, 9, 5);
			graph->AddBidirectionalEdge(6, 11, 5);
			graph->AddBidirectionalEdge(7, 8, 8);
			graph->AddBidirectionalEdge(7, 10, 7);
			graph->AddBidirectionalEdge(8, 9, 2);
			graph->AddBidirectionalEdge(8, 12, 9);
			graph->AddBidirectionalEdge(9, 10, 5);
			graph->AddBidirectionalEdge(9, 12, 9);
			graph->AddBidirectionalEdge(10, 14, 5);

			//Populate our nodes
			for (int i = 0; i < graph->V; i++)
			{
				Node* n = new Node(i, INT_MAX, to_string(i + 1));
				graph->nodes[i] = n;
			}

			//Update adjacency list
			graph->UpdateAdjacencyList();
			//Get input and update adj matrix
			graph->PrintAdjMatrix();
			graph->PrintAdjList();
			break;
		}
		case 3:
		{
			int n, density, mode;
			cout << "Enter number of nodes: ";
			cin >> n;
			cout << "Enter density: ";
			cin >> density;
			cout << "Enter type DIRECTIONAL:0 or BIDIRECTIONAL:1 : " << endl;
			cin >> mode;
			graph->type = GRAPH_TYPE(mode);
			graph->GenerateRandomGraph(n, density);
			graph->PrintAdjMatrix();
			graph->PrintAdjList();
			break;
		}
		case 4:
		{
			cout << "What name is the graph called?: ";
			std::string fileName;
			cin >> fileName;
			string filePath = "data/Prim/Graphs/" + fileName + ".csv";
			if (graph->LoadGraph(filePath))
				cout << "Graph sucessfully imported from " + filePath << endl;

			break;
		}
		case 5:
		{
			cout << "What name is this graph called?: ";
			std::string fileName;
			cin >> fileName;
			string filePath = "data/Prim/Graphs/" + fileName + ".csv";
			if (graph->ExportGraph(filePath))
				cout << "Graph successfully exported to " + filePath << endl;
			filePath = "data/Prim/Graphs/" + fileName + "_mst.csv";
			if (mst->ExportGraph(filePath))
				cout << "MST successfully exported to " + filePath << endl;
			break;
		}
		case 6:
		{
			graph->PrintAdjMatrix();
			graph->PrintAdjList();
			break;
		}
		case 7:
		{
			mst->PrintAdjMatrix();
			mst->PrintAdjList();
			break;
		}
		case 8:
		{
			//Update our MST graph bnased on current graph
			mst->SetupMST(graph);
			//Build our MST
			Prim::BuildMST(graph, mst, 0);
			mst->PrintAdjMatrix();
			mst->PrintAdjList();
			cout << "Edges: " << mst->E << endl;
			break;
		}
		case 9:
		{
			system("cls");
			break;
		}
		case 10:
		{
			break;
		}
		default:
		{
			break;
		}
		}
	} while (choice != 10);
	return 0;
}
#endif