/*************************************************************************
** Program name: babyFaceOrHeel.cpp
** Class name: CS325-400
** Author: Ben Fridkis
** Date: 5/9/2018
** Description: Program to designate wrestler type (BabyFace or Heel)
**              if possible from a set (graph) of wrestler names and
**              rivalries. If the rivalry relations are such that
**              sides can be designated, such designation is output.
**              Otherwise, the program indicates that rivalry designation
**              is not possible, given the specific data set.
*************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <queue>
using std::cout;
using std::cerr;
using std::endl;
using std::ifstream;
using std::string;
using std::vector;
using std::map;
using std::queue;

enum wrestlerType {BabyFace, Heel, undetermined};
enum visited {WHITE, GREY, BLACK};

struct Wrestler{
    string name;
    wrestlerType type;
    vector<Wrestler*> adj;          //Adjacency list
    visited status;
    //int distance;                 //In this particular application of BFS, distance isn't needed.

    Wrestler(){
        type = undetermined;        //Default status is undetermined, but first wrestler is given status of Babyface (see line 92).
        //distance = -1;            //In this particular application of BFS, distance isn't needed.
        status = WHITE;             //By default vertices are set to WHITE.
    }
};

map<string, Wrestler> establishGraph(char* inputFile){
    ifstream dataIn;
     if(inputFile == nullptr){
        cout << "\nMust enter file name when running program." << endl
             << "Type './babyFaceOrHeel file.txt' in command line," << endl
             << "replacing 'file.txt' with the name of your file.\n" << endl;
        exit(1);
    }
    try{
        dataIn.open(inputFile);
        dataIn.exceptions (ifstream::failbit | ifstream::badbit);
    }
    catch(ifstream::failure e){
        cerr << "\nFile cannot be found or opened.\n" << endl;
        exit(1);
    }
    //Establishes vertices (representing wrestlers) of graph.
    int numberOfWrestlers;
    dataIn >> numberOfWrestlers;
    map<string, Wrestler> wrestlers;
   for(int i = 0; i < numberOfWrestlers; i++){
       string wrestlerName;
       dataIn >> wrestlerName;
       wrestlers[wrestlerName] = Wrestler();
    }
    //Assigns adjacency lists based on rivalries
    int numberOfRivalries;
    dataIn >> numberOfRivalries;
    for(int i = 0; i < numberOfRivalries; i++){
        string rival_1, rival_2;
        dataIn >> rival_1;
        dataIn >> rival_2;
        Wrestler* rival_1sRival = &wrestlers[rival_2];
        wrestlers[rival_1].adj.push_back(rival_1sRival);
        Wrestler* rival_2sRival = &wrestlers[rival_1];
        wrestlers[rival_2].adj.push_back(rival_2sRival);
    }

    dataIn.close();
    return wrestlers;
}

void BFS(map<string, Wrestler>& wrestlers){
    map<string, Wrestler>::iterator it;
    for(it = wrestlers.begin(); it != wrestlers.end(); it++){
        //Q is first initialized (line 100) with the first wrestler encountered in the map.
        //The if statement (line 98) repeats for any remaining non-connected graph segments,
        //initializing Q with next non-connected vertex to repeat the BFS procedure.
        if(it->second.status == WHITE){
            queue<Wrestler*> Q;
            it->second.type = BabyFace;              //This first wrestler (of each connected segment of G) is designated a BabyFace
            Q.push(&(it->second));
            while(Q.size() > 0){
                Wrestler* u = Q.front();             //The first wrestler encountered of any non-connected graph segment is considered the "source" vertex for the BFS
                for(unsigned i = 0; i < u->adj.size(); i++){
                    if(u->adj[i]->status == WHITE){
                        u->adj[i]->status = GREY;
                        //u->adj[i]->distance = u->distance + 1;    //In this particular application of BFS, distance isn't needed.
                        if(u->type == BabyFace){
                            u->adj[i]->type = Heel;                 //Any adjacent wrestler must be designated on the opposing team
                        }
                        else{
                                u->adj[i]->type = BabyFace;         //See comment above (line 108)
                        }
                        Q.push(u->adj[i]);
                    }
                    else{                                           //If an adjacent wrestler has been designated previously on the same team as is the current wrestler,
                        if(u->type == u->adj[i]->type){             //a conflict is detected (i.e. the data set is such that designations cannot be determined). The program prints and terminates accordingly.
                            cout << "\nNo. Impossible to designate wrestler types given the current data set.\n"
                                 << endl;
                            exit(0);
                        }
                    }
                }
                u->status = BLACK;
                Q.pop();
            }
        }
    }
}

void printStatus(map<string, Wrestler>& wrestlers, wrestlerType type){
    string wType;
    if(type == BabyFace){
        wType = "Babyfaces";
    }
    else{
        wType = "Heels";
    }
    cout << wType + ": ";
    map<string, Wrestler>::iterator it;
    for(it = wrestlers.begin(); it != wrestlers.end(); it++){
        if(type == BabyFace && it->second.type == BabyFace){
            cout << it->first << " ";
        }
        if(type == Heel && it->second.type == Heel){
            cout << it->first << " ";
        }
    }
}

int main(int argc, char *argv[]){

    map<string, Wrestler> wrestlers = establishGraph(argv[1]);
    BFS(wrestlers);

    cout << "\nYes Possible" << endl;
    printStatus(wrestlers, BabyFace);
    cout << endl;
    printStatus(wrestlers, Heel);
    cout << "\n" << endl;

    return 0;
}
