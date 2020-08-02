学习笔记

//1.冒泡排序
int bubbleSort(vector<int>& array){
	int n = array.size();
	for(int i = 0; i < n -1; i++){
		for(int j = 0; j < n - 1; j++){
			if(array[j] > array[j+1]){
				swap(array[j],array[j+1]);
			}
		}
	}
}
//2.选择排序
int selectSort(vector<int> &array){
	int n = array.size();
	int minIndex = 0;
	int tmp = 0;
	for(int i = 0; i < n - 1;i++){
		minIndex = i;
		for(int j =  i + 1; j< n; j++){
			if(array[j] < array[minIndex]){
				minIndex = j;
			}
		}
		swap(array[i],array[minIndex]);
	}
}
//3.插入排序
int insertSort(vector<int> &array){
	int n = array.size();
	int prevIndex,curNum;
	for(int i = 1; i < n; i++){
		prevIndex = i - 1;
		curNum = array[i];
		while(prevIndex >= 0 && array[preIndex] > curNum){
			array[prevIndex + 1] = array[preIndex];
			prevIndex--;
		}
		array[prevINdex + 1] = currNum;
	}
}