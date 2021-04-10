/*

Project: Digital Design 1
		  Kmap for three inputs

Group:  Mohamed Basiouny
		Mahmoud Elshinawy
		
 
 
 */

#include <iostream>
#include <vector>
using namespace std;

struct cell {
	int A, B, C, value=0,dec=0;
};

void set_zero(cell kmap_arr[][4]) {

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 4; j++) {
			kmap_arr[i][j].value = 0;
		}
	}
}

void set_dec(cell kmap_arr[][4]) {

	for (int i = 0; i < 2; i++) {

		
		for (int j = 0; j < 4; j++) {
			if (i==0)
			kmap_arr[i][j].dec = j;
			else if(i==1)
				kmap_arr[i][j].dec = j+4;

					}
	}

	swap(kmap_arr[0][2], kmap_arr[0][3]);
	swap(kmap_arr[1][2], kmap_arr[1][3]);
	}

void set_literals(cell kmap_arr[][4]) {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 4; j++) {
			if (i == 0) {
				kmap_arr[i][j].A = 0;
			}
			if (i == 1) {
				kmap_arr[i][j].A = 1;
			}
			switch (j) {
			case 0:
				kmap_arr[i][j].B = 0;
				kmap_arr[i][j].C = 0;
				break;
			case 1:
				kmap_arr[i][j].B = 0;
				kmap_arr[i][j].C = 1;
				break;
			case 2:
				kmap_arr[i][j].B = 1;
				kmap_arr[i][j].C = 1;
				break;
			case 3:
				kmap_arr[i][j].B = 1;
				kmap_arr[i][j].C = 0;
				break;
			}
		}
	}


}

void set_map(cell kmap_arr[][4]) {
	set_zero(kmap_arr);
	set_dec(kmap_arr);
	set_literals(kmap_arr);
}

void input_user(cell kmap_arr[][4],int input [],int min_number) {
	cout << "enter the location of your minterms" << endl;
	for (int i = 0; i < min_number; i++) {
		cin >> input[i];
		while ((input[i] < 0) || (input[i] > 7)) {
			cout << "Please enter a number between 0 & 7" << endl;
			cin >> input[i];
		}
		
		for (int k = 0; k < 2; k++) {
			for (int j = 0; j < 4; j++) {
				if (kmap_arr[k][j].dec == input[i]) {
				kmap_arr[k][j].value = 1;
				break;
				}
			}
		}
	}

}

void print_map(cell kmap_arr[][4]) {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 4; j++) {
			cout << kmap_arr[i][j].value << "\t";
		}
		cout << endl;
	}
}

bool isAll_thesame(cell kmap_arr[][4],int a) {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 4;j++) {
			if (kmap_arr[i][j].value != a)
				return false;


		}


	}
	return true;

}

void print_func(vector<cell>& kmap) {
	bool flag = true; int i = 0;
	while (flag && i<int(kmap.size() - 1)) {
		if (kmap[i].A != kmap[i + 1].A)
			flag = false;
		else
			i++;
	}
	if (flag) {
		if (kmap[0].A == 0)
			cout << "~A";
		else if (kmap[0].A == 1)
			cout << "A";
	}

	flag = true; i = 0;
	while (flag && i<int(kmap.size() - 1)) {
		if (kmap[i].B != kmap[i + 1].B)
			flag = false;
		else
			i++;
	}
	if (flag) {
		if (kmap[0].B == 0)
			cout << "~B";
		else if (kmap[0].B == 1)
			cout << "B";
	}

	flag = true; i = 0;
	while (flag && i<int(kmap.size() - 1)) {
		if (kmap[i].C != kmap[i + 1].C)
			flag = false;
		else
			i++;
	}
	if (flag) {
		if (kmap[0].C == 0)
			cout << "~C";
		else if (kmap[0].C == 1)
			cout << "C";
	}

	cout << " + ";
}

void map_delete(vector<cell>& kmap, int num) {
	for (int i = 0; i < num; i++)
		kmap.pop_back();
}
void transfer_bool(bool& a,bool& b) {
	b = a;
}

int main() {
	cell kmap_arr[2][4];
	set_map(kmap_arr);
	vector <cell> kmap;
	vector<cell> copy;

	int min_number;
	cout << "How many minterms do you have\n";
	cin >> min_number;
	while (min_number > 8)
	{
		cout << "ERROR! PLEASE RE-ENTER A VALUE BETWEEN 0 & 8" << endl;
		cin >> min_number;
	}

	int* input;
	input = new int[min_number];
	input_user(kmap_arr, input, min_number);
	print_map(kmap_arr);

	/* ----------------------------------------------------------------------------------------------------------- */
	if (isAll_thesame(kmap_arr, 1))
		cout << "f= 1" << endl;
	if (isAll_thesame(kmap_arr, 0) || min_number == 0)
		cout << "f= 0" << endl;


	if (!isAll_thesame(kmap_arr,1)&&!isAll_thesame(kmap_arr,0)){
	bool flag = true; bool cons = true; bool pros = true; bool squareflag = true; bool four_below = true;
	cout << "f= ";
	if (kmap_arr[0][0].value == 1 && kmap_arr[0][3].value == 1 && kmap_arr[1][0].value == 1 && kmap_arr[1][3].value == 1) {

		flag = false;
		copy.push_back(kmap_arr[0][0]);
		copy.push_back(kmap_arr[0][3]);
		copy.push_back(kmap_arr[1][0]);
		copy.push_back(kmap_arr[1][3]);

		print_func(copy);
		map_delete(copy, copy.size());
	}


	int k(0), s(0);
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 4; j++) {
			k = i; s = j;
			if (i == 0) {
				if (j == 0) {
					if (kmap_arr[k][s].value == 1) {
						kmap.push_back(kmap_arr[k][s]);
						s++;
						while (s < 4 && kmap_arr[k][s].value == 1) {

							kmap.push_back(kmap_arr[k][s]);
							s++;

						}

						if (kmap.size() == 4) {
							print_func(kmap);
							map_delete(kmap, 4);
							cons = false;
							pros = false;
						}
						map_delete(kmap, kmap.size());
						k = i; s = j; int change(0);

						 //here comes some coding
						while (change < 4) {
							if (kmap_arr[k][s].value == 1) {
								kmap.push_back(kmap_arr[k][s]);
							}
							if (change == 0)
								s++;

							else if (change == 1) {
								s = j;
								k++;
							}
							else if (change == 2)
								s++;
							change++;
						}

						if (kmap.size() == 4) {
							print_func(kmap);
							map_delete(kmap, 4);
							squareflag = false;
						}

						else if (kmap.size() == 3) {
							if (kmap_arr[i + 1][j + 1].value == 0) {
								copy.push_back(kmap[0]);
								copy.push_back(kmap[2]);
								map_delete(kmap, 1);
								if (cons)
									print_func(kmap);
								if (flag) {
									print_func(copy);
								}
								map_delete(kmap, kmap.size());
								map_delete(copy, copy.size());
							}
							else if (kmap_arr[1][0].value == 0) {
								map_delete(kmap, 1);
								if (cons) {
									print_func(kmap);
									map_delete(kmap, kmap.size());
								}
							}
							else if (kmap_arr[0][1].value == 0) {
								copy.push_back(kmap[0]);
								copy.push_back(kmap[1]);
								if (flag) {
									print_func(copy);
								}
								map_delete(copy, copy.size());
							}
						}
						else if (kmap.size() == 2) {
							if (kmap_arr[i + 1][j + 1].value == 0) {
								if (kmap_arr[0][1].value == 1)
									print_func(kmap);
								else
									if (flag)
										print_func(kmap);
							}
							else {
								map_delete(kmap, 1);
								if (kmap_arr[0][3].value == 1)
									if (flag) {
										kmap.push_back(kmap_arr[0][3]);
										print_func(kmap);
										map_delete(kmap, kmap.size());
									}

							}
						}
						else if (kmap.size() == 1) {
							if (kmap_arr[0][3].value == 1)
								if (flag) {
									kmap.push_back(kmap_arr[0][3]);
									print_func(kmap);
									map_delete(kmap, kmap.size());
								}
						}

						map_delete(kmap, kmap.size());
						map_delete(copy, copy.size());

					}
				}

				else {
					int k2(0), s2(0);
					if (kmap_arr[i][j].value == 1) {
						k2 = i; s2 = j; int change2(0);


						while (change2 < 4) {
							if (kmap_arr[k2][s2].value == 1) {
								kmap.push_back(kmap_arr[k2][s2]);
							}
							if (change2 == 0)
								s2++;

							else if (change2 == 1) {
								s2 = j;
								k2++;
							}
							else if (change2 == 2)
								s2++;
							change2++;
						}

						if (kmap.size() == 4) {
							print_func(kmap);
							map_delete(kmap, 4);
							squareflag = false;
						}
						else if (kmap.size() == 3) {
							if (kmap_arr[i + 1][j + 1].value == 0) {
								copy.push_back(kmap[0]);
								copy.push_back(kmap[2]);
								map_delete(kmap, 1);

								if (cons) {
									print_func(kmap);
								}
								if (squareflag) {
									print_func(copy);
								}
							}
							else if (kmap_arr[i + 1][j].value == 0) {
								map_delete(kmap, 1);
								if (pros) {
									print_func(kmap);
								}


							}
							else if (kmap_arr[i][j + 1].value == 0) {
								map_delete(kmap, 1);
								if (squareflag) {
									print_func(kmap);
								}

							}
							squareflag = false;
						}
						else if (kmap.size() == 2) {
							if (kmap_arr[i + 1][j + 1].value == 0) {
								if (kmap_arr[i][j + 1].value == 1)
									if (pros)
										print_func(kmap);
									else
										if (squareflag)
											print_func(kmap);

							}
							else {
								map_delete(kmap, 1);
								if (kmap_arr[i][j - 1].value == 0)
									print_func(kmap);

								map_delete(kmap, kmap.size());


							}
							squareflag = false;
						}
						else if (kmap.size() == 1) {
							if (j == 3) {
								if (kmap_arr[0][0].value == 0)
									print_func(kmap);
							}
							else {
								if (kmap_arr[i][j - 1].value == 0)
									print_func(kmap);
							}
							squareflag = false;
						}
						map_delete(kmap, kmap.size());
						map_delete(copy, copy.size());
					}
				}
			}
			else if (i == 1) {
				int k3 = i, s3 = j;
				if (kmap_arr[0][j].value == 0 || kmap_arr[0][j + 1].value == 0) {
					if (kmap_arr[k3][s3].value == 1) {
						kmap.push_back(kmap_arr[k3][s3]);
						s3++;
						while (s3 < 4 && kmap_arr[k3][s3].value == 1) {
							kmap.push_back(kmap_arr[k3][s3]);
							s3++;
						}
						if (kmap.size() == 4) {
							print_func(kmap);
							map_delete(kmap, 4);
							four_below = false;
						}
						else if (kmap.size() == 3) {

							map_delete(kmap, 1);
							if (four_below)
								print_func(kmap);

							map_delete(kmap, kmap.size());

						}

						else if (kmap.size() == 2) {
							if (four_below)
								print_func(kmap);
							map_delete(kmap, kmap.size());

						}
						else if (kmap.size() == 1) {
							if (kmap_arr[0][j].value == 0 && kmap_arr[0][j + 1].value == 0) {
								if (j == 0) {
									if (kmap_arr[1][3].value == 1) {
										if (flag) {
											kmap.push_back(kmap_arr[1][3]);
											print_func(kmap);
											map_delete(kmap, kmap.size());
										}
									}
									else if (j == 3) {
										if (kmap_arr[1][0].value == 0 && kmap_arr[1][2].value == 0) {
											print_func(kmap);
											map_delete(kmap, kmap.size());
										}
									}
									else {
										if (kmap_arr[i][j - 1].value == 0)
											print_func(kmap);
										map_delete(kmap, kmap.size());
									}
								}
							}
						}
					}
				}
			}
		}
		map_delete(kmap, kmap.size());
		map_delete(copy, copy.size());
	}
}
	cout << "\b\b" << " " << endl;    // to overwrite the last + sign with space character	
	delete[] input;
	return 0;
}

