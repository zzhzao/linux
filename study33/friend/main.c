#include <ncurses.h>
#include <math.h>

#define M_PI 3.14f

// 心形曲线函数
float heart_function(float t) {
    return pow(sin(t), 3);
}

int main() {
    initscr();          // 初始化 ncurses
    curs_set(0);        // 隐藏光标
    noecho();           // 不显示输入字符
    
    int height, width;
    getmaxyx(stdscr, height, width);  // 获取终端尺寸
    
    // 心形参数
    float scale = 8.0;
    int offset_x = width / 2;
    int offset_y = height / 2;
    
    // 绘制心形
    for (float t = 0; t < 2 * M_PI; t += 0.01) {
        float x = scale * heart_function(t);
        float y = scale * (0.8125 * cos(t) - 0.3125 * cos(2*t) - 0.125 * cos(3*t) - 0.0625 * cos(4*t));
        
        int screen_x = offset_x + (int)(x * 2);  // 乘以2调整宽高比
        int screen_y = offset_y - (int)y;        // 注意Y轴方向
        
        if (screen_x >= 0 && screen_x < width && screen_y >= 0 && screen_y < height) {
            mvprintw(screen_y, screen_x, "❤");  // 使用心形符号
        }
    }
    
    // 添加提示信息
    mvprintw(height - 1, 0, "Press any key to exit...");
    refresh();          // 刷新屏幕显示
    
    getch();            // 等待按键
    endwin();           // 结束 ncurses
    
    return 0;
}
