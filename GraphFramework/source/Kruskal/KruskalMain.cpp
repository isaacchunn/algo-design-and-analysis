#include "../Application.h"
#ifdef KRUSKAL

#include <iostream>
#include "../Graph/Graph.h"
#include "../Graph/Node.h"
#include "Kruskal.h"

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
		cout << "---Kruskal Interface---" << endl;
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
			break;
		}
		//lecture graph
		case 2:
		{
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
			string filePath = "data/Kruskal/Graphs/" + fileName + ".csv";
			if (graph->LoadGraph(filePath))
				cout << "Graph sucessfully imported from " + filePath << endl;

			break;
		}
		case 5:
		{
			cout << "What name is this graph called?: ";
			std::string fileName;
			cin >> fileName;
			string filePath = "data/Kruskal/Graphs/" + fileName + ".csv";
			if (graph->ExportGraph(filePath))
				cout << "Graph successfully exported to " + filePath << endl;
			filePath = "data/Kruskal/Graphs/" + fileName + "_mst.csv";
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
		}
		case 8:
		{
			//Update our MST graph bnased on current graph
			mst->SetupMST(graph);
			//Build our MST
			Kruskal::BuildMST(graph, mst, 0);
			mst->PrintAdjMatrix();
			mst->PrintAdjList();
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