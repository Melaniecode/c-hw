#include <stdio.h>
#include <stdlib.h>

// 原型宣告
void shuffle(int arr[], int n);
void tuningFork(int stone);

//主程式
int main() {
  int hp = 100;
  int count = 0;
  int bomb  = 2;
  int choice;
  int arr[7] = {3, 2, 2, 1, 1, 1, 1}; //堅硬 -> 3, 稍硬 -> 2, 普通 -> 1

  shuffle(arr, 7);

  printf("<< 歡迎挑戰 >>\n");
  
  //開始遊戲
  while(1) {
    printf("第%d顆石頭 波奇HP: %d 炸彈數量: %d\n", count+1, hp, bomb);
    printf("<1>音叉 <2>鐵鎚 <3>電鑽 <4>炸彈 <5>放棄 >> 選擇：");
    scanf("%d", &choice);
  
    switch(choice) {
      case 1:
        tuningFork(arr[count]);
        break;
      case 2: 
        if(arr[count] == 1){
          hp -= 10;
          count++;
          printf("<< 成功擊碎石頭 >>\n");
          break;
        }
        else{
          printf("<< 石頭產生裂痕 >>\n");
          break;
        }
      case 3: 
        if(arr[count] == 1 || arr[count == 2]){
          hp -= 20;
          count++;
          printf("<< 成功擊碎石頭 >>\n");
          break;
        }
        else{
          printf("<< 石頭產生裂痕 >>\n");
          break;
        }
      case 4: 
        if(bomb > 0){
          bomb --;
          count++;
          printf("<< 成功擊碎石頭 >>\n");
          break;
        }
        else {
          printf("炸彈已完全用盡qq\n");
          break;
        }
      case 5: 
        printf("<< 尋寶失敗 >> \n");
        return 0;
    }
    if(hp <= 0) {
      printf("HP 已耗盡...\n");
      printf("<< 尋寶失敗 >>");
      break;
    }
    if(count >= 7) {
      printf("<<恭喜獲得寶藏>>\n");
      break;
    }
  }
  system("pause");
  return 0;
}

 // 使用Fisher-Yates演算法
void shuffle(int arr[], int n) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1); // 0到i隨機
        int temp = arr[i];

        // i的值和j的值互換
        arr[i] = arr[j]; 
        arr[j] = temp;
    }
}
// 音叉
void tuningFork(int stone) {
  int rand_value = rand() % 100 + 1; // 1到100隨機
  if (stone == 3) {
    if(rand_value <= 75)
      printf("<< 音叉發出沈重聲 >>\n");
    else
      printf("<< 音叉發出清脆聲 >>\n");
  }
  else if (stone == 2) {
    if (rand_value <= 50)
      printf("<< 音叉發出沈重聲 >>\n");
    else
      printf("<< 音叉發出清脆聲 >>\n");
  } 
  else {
    if (rand_value <= 10) 
      printf("<< 音叉發出沈重聲 >>\n");
    else
      printf("<< 音叉發出清脆聲 >>\n");
  }
}