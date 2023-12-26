# **迷宮**
**：欸欸我迷路了，請問通往你心裡的路怎麼走**

# **遊戲介紹**

你將置身於一個隨機生成的迷宮中，操控一個表示玩家的符號 ' ＠ '，目標是找到出口' ！ '，成功攻略你的暈船對象

## **規則**

Very easy，連我阿嬤都會
1. 起點位於迷宮的左上角，而出口則在迷宮的最下方列隨機移動。通過操控鍵盤按鍵，將玩家符號移動至出口處
2. 牆壁將阻礙你的前進，小心規劃你的路線，不要撞牆，不然我會笑你

   （註：人生不可能一帆風順，如果你碰壁就勇敢撞下去，當上帝關了你Ｎ扇門，同時會幫你開一扇窗的）
   
３. 每移動幾步，迷宮就會隨機生成新的路線。就像你暈船對象的心一樣捉摸不透 ==

## **操作方式**
- ＂Ｗ＂：向上移動
- ＂Ａ＂：向左移動
- ＂Ｓ＂：向下移動
- ＂Ｄ＂：向右移動

## **遊戲畫面**
- ' ＠ '：玩家
- ' ！ '：出口
- ' ＃ '：牆壁
- 空格：通道

# **程式結構圖**
1. maze.h - 標頭檔
   - 判斷作業系統
   - 定義變數
   - 宣告函數原型
2. main（） - 主函式
   - 顯示歡迎畫面  
   - 判斷作業系統，決定該使用 _getch（）或 getKeyPress（）來獲取按鍵
   - 計算遊戲時間，並儲存最佳遊玩時間
   - 結束遊戲
   - 按鍵判斷是否重新開始
3. generateMaze（） - 副函式
   - 隨機生成迷宮
   - 確保起點與終點是通道
4. generateExits（） - 副函式
   - 生成迷宮的出口
5. displayMaze（） - 副函式
   - 顯示迷宮
6. movePlayer（） - 副函式
   - 移動玩家
7. writeElapsedTime（） - 副函式
   - 寫入每次遊戲結束經過的時間到文件中
# **流程圖**

# **技術使用說明**

# **開發時間**
 2023/12/10，1Hr
 
 2023/12/16，1Hr
 
 2023/12/17，5Hr
 
 2023/12/18，3Hr

 2023/12/23，3Hr

 2023/12/26，3Hr

 2023/12/27，2Hr
