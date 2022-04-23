#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int FLAG = 0;
class port
{

  public:
 int id = 0;
 int link_port = 0;
 string bridge_name = "";

 void set(int a)
 {
  link_port = a;
  //Pnk_port = 1;
 }
};

class bridge
{

  private:
  public:
 string name;
 map<int, port> ports;
 map<string, port> trans;
 port *get_port(int id)
 {
  map<int, port>::iterator iter;
  iter = ports.find(id);
  return &iter->second;
 };
 void update(string host, int p)
 {
  map<string, port>::iterator iter;
  iter = trans.find(host);
  if (iter != trans.end())
  {
   return;
  }
  else
  {
   port *a = get_port(p);
   trans.insert(pair<string, port>(host, *a));
  }
 };
};

static map<string, bridge> net;

//bridge find_bridge(string name)
//{
//
//
//}
void broadcast(string bridge_id, string host, int p_id)
{

 bridge *source = &net.find(bridge_id)->second;
 source->update(host, p_id);

 map<string, port>::iterator iter;
 cout << source->name << " "
   << " table" << endl;
 for (iter = source->trans.begin(); iter != source->trans.end(); iter++)
  cout << iter->first << "  " << iter->second.id << endl;

 map<int, port>::iterator iter_p;
 for (iter_p = source->ports.begin(); iter_p != source->ports.end(); iter_p++)
 {
  if (iter_p->first == p_id && FLAG != 0)
   continue;
  if (iter_p->second.bridge_name.empty())
   continue;
  FLAG = 1;
  broadcast(iter_p->second.bridge_name, host, iter_p->second.link_port);
 }
};
int main()
{
 int N = 0;
 int N_p = 1;
 int id = 0;
 int id_2;
 string A = "";
 bridge bridge_temp;
 port p;
 cout << "Please input the total number of brideges :" << endl;
 cin >> N;
 for (int i = 0; i < N; i++)
 {
  cout << "Please input the name of bridege " + to_string(i) << endl;
  cin >> A;
  bridge_temp.name = A;
  net.insert(pair<string, bridge>(A, bridge_temp));
 }
 cout << "Please input ports of each bridge " << endl;
 for (map<string, bridge>::iterator ii = net.begin(); ii != net.end(); ii++)
 {
  cout << "Please input the total ports of bridge " + ii->second.name << endl;
  cin >> N_p;

  for (int i_p = 0; i_p < N_p; i_p++)
  {
   cout << "Please input the id of port " + to_string(i_p + 1) << endl;
   cin >> id;
   p.id = id;
   //  p.set(0);
   //  p.bridge_name = "";
   //  cout<<"Please input link bridge and the link port id,if null, input NOP"<<endl;
   //  cin>>A;
   //  if(A.compare("NOP")!=0)
   //  {
   //   p.bridge_name = A;
   //   cin>>id_2;
   //   p.set(id_2);
   //  }
   ii->second.ports.insert(pair<int, port>(id, p));
  }
 }

 cout << "Please input links among bridges, in the format of " << endl
   << "Bridge_A Port_1 Bridge_B Port_2" << endl
   << "end with END" << endl;
 cin >> A;
 string B = "";

 while (A.compare("END") != 0)
 {
  cin >> id;
  cin >> B;
  cin >> id_2;
  // map<string,bridge>::iterator iter_b;
  // iter_b = net.find(name);
  // iter_b->second;
  net.find(A)->second.get_port(id)->set(id_2);
  net.find(A)->second.get_port(id)->bridge_name = B.c_str();

  net.find(B)->second.get_port(id_2)->set(id);
  net.find(B)->second.get_port(id_2)->bridge_name = A.c_str();
  cout << "Next link :" << endl;
  cin >> A;
 }
 while (true)
 {
  cout << "Please input the location of Hosts, in the format of " << endl
    << "Host_name Bridge_name Port_id" << endl;
  cin >> A;
  cin >> B;
  cin >> id;
  broadcast(B, A, id);
 }
 return 0;
}
