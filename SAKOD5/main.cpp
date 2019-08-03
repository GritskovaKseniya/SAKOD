//Lab5List.cpp
/*
����:���������� ������� ���-������� � ������������: ���������� ���-�������,
���������� (����-��������), �������� ��������� �� ���-������� �� �����,
����� � ������� �� �����, ������ �������.
���������: �������� �.�.
����:
*/
#include <iostream>

using namespace std;

const int NOT_FOUND = -1;
// ����� ���-�������
class Hash_table {
// ���������� ������� � �������
private:
// ��������� ��� ����������� �������� ������
struct cell {
  const int data;  int key;  cell *p_next;
  cell(const int/*T&*/ cell_data, int cell_key, cell * cell_next = NULL) :
      data(cell_data), key(cell_key), p_next(cell_next) { } };
// ������ �������, ������ ������� ��������� �� ������ �����
cell **table;
unsigned int table_size;
// �������� ��� ������
int T_notfound;
// ���������� ���-������� (������� �� �������)
unsigned int hash(int key) {  return static_cast<unsigned int>(key % table_size); }
// ����� �� ������� �� �������� �����
cell *find_cell(int key) {
  unsigned int slot = hash(key); cell *cp = NULL;
  for(cp = table[slot]; cp != NULL; cp = cp->p_next) { if(cp->key == key) return cp; }
  return cp; }
// ���������� ������������ � ����������� �����������
Hash_table(const Hash_table &);
Hash_table & operator=(const Hash_table &);
// ������������� �������
public:
// �����������
Hash_table(unsigned int size, const int notfound) : table_size(size), T_notfound(notfound) {
  table = new cell*[table_size];  for(unsigned int i = 0; i < size; table[i++] = NULL); }
// ����������
~Hash_table() {
  for(unsigned int i = 0; i < table_size; i++) {
    cell *cp = NULL, *cp_next = NULL; if((cp = table[i]) == NULL) continue;
    else cp_next = cp->p_next;
    // ������� �������� ������
    while(true) {
      delete cp; if(cp_next == NULL) break;
      cp = cp_next; cp_next = cp_next->p_next; } }
  delete [] table; }
// ���������� �������� � ������� � ������ key (������� ���������� true � ������ ������)
bool add(const int/*T&*/ item, int key) {
  // ���������� ���������� �������� � ������������ ������
  if(find_cell(key) != NULL) return false;
  // ��������� ���-�������, ��������� �������
  unsigned int slot = hash(key);
  if(table[slot] == NULL) table[slot] = new cell(item, key);
  else table[slot] = new cell(item, key, table[slot]);
  return true; }
// �������� �������� �� ������� � ������ key
void remove(int key) {
  unsigned int slot = hash(key); cell *cp_prev = table[slot];
  // �������� ���, ������� ������
  if(cp_prev == NULL) return;
  // ����������� ������ ��� ������� ��������
  if(cp_prev->key == key) { table[slot] = cp_prev->p_next; delete cp_prev; return; }
  // �������� ������������� ��������
  for(cell *cp = cp_prev->p_next; cp != NULL; cp_prev = cp_prev->p_next, cp = cp->p_next) {
    if(cp->key == key) {
      cp_prev->p_next = cp->p_next; delete cp; return; } } }
// ����� �� ����� � �������
const int/*T&*/ find(int key) { cell *cp = find_cell(key); return (cp ? cp->data : T_notfound); }
// ������ �������
void print() {
  std::cout << std::endl << "slot #" << std::endl << "------" << std::endl;
  for(unsigned int index = 0; index < table_size; ++index) {
    std::cout << index << ":       ";
    for(cell *cp = table[index]; cp != NULL; cp = cp->p_next) {
      std::cout << "[" << cp->data << ", " << cp->key << "]"; }
    std::cout << std::endl; }
  std::cout << std::endl; } };

int main(){
	int menuPos = 0, t_size = 0, notFound = NOT_FOUND;
	// ����������� ������ ���-�������
	while(0 == t_size) {
		std::cout << "-- Enter the hash table size (>= 50 recomended): " << std::endl;
		std::cin >> t_size; }
	// ������� ������
	Hash_table *pTable = new Hash_table(t_size, notFound);
	std::cout << "Created hash table with size: " << t_size << std::endl;
	// ���������� ������� �������� ����
	do{	std::cout << "    Please type the command number" << std::endl;
		std::cout << "0 - Exit" << std::endl;
		std::cout << "1 - Add one element to table (number)" << std::endl;
		std::cout << "2 - Delete one element from table (number)" << std::endl;
		std::cout << "3 - Print the hash table" << std::endl;
		std::cout << "4 - Find the element in the table" << std::endl;
		std::cout << "    Enter the command: " << std::endl;
		std::cin >> menuPos;
		int data = 0, key = 0, number = 0; bool sc = false;
		// ��������� �������� � ����������� �� ���������� ������ ����
		switch(menuPos) {
			case 0: // ����� �� ���������
				std::cout << "... End of work ..." << std::endl; break;
			case 1: // ������� �������
				std::cout << "-- Enter the element value (add): " << std::endl;
				std::cin >> data; std::cout << "-- Enter the element key (add): " << std::endl;
				std::cin >> key; sc = pTable->add(data, key);
				if(!sc) { // ���� �������� ����������
					std::cout << "Can't add the element. The element is in the table!!" << std::endl;} break;
			case 2: // ������ �������
				std::cout << "-- Enter the element key (delete): " << std::endl;
				std::cin >> key; pTable->remove(key); break;
			case 3: // ���������� �������
				pTable->print(); break;
			case 4: // ������ ������� � ������� �� �����
				std::cout << "-- Enter the element key (find): " << std::endl;
				std::cin >> key; data = pTable->find(key);
				// ����� ������� ��� ���
				if(NOT_FOUND == data) { // �� ������
					std::cout << "The element is not found in the table !!!" << std::endl; }
				else { // ������
					std::cout << "The element value is (find): " << data << std::endl; }
				break;
			default: // ������ ���������� ��������� ��������
				std::cout << "!!! Wrong command number !!!" << std::endl; break; }
	}while(menuPos); // ������� ������
	// ������� ������ ��� ������ �� ���������
	if(pTable) { delete pTable; }
	// ����� �� ���������
	return 0; }
