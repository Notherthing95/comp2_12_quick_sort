#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include "../include/lib_func.h"

static void swap(item* a, item* b)
{
    item temp = *a;
    *a = *b;
    *b = temp;
}

static item* partition(item* low, item* high)
{
    item* pivot = high;
    item* i = low - 1;

    for (item* j = low; j < high; ++j) {
        if (j->key <= pivot->key) {
            ++i;
            swap(i, j);
        }
    }
    swap(i + 1, high);
    return i + 1;
}

// クイックソート(引数が不適切であればfalseを返す)
bool quick_sort(item* begin, const item* end)
{
    // ToDo: クイックソートで並び替えてください

    if (begin == nullptr || end == nullptr || begin >= end) {
        return false;
    }
    if (end - begin <= 1) {
        return true;
    }

    item* stack[64];
    int top = -1;

    stack[++top] = begin;
    stack[++top] = (item*)(end - 1);

    while (top >= 0) {
        item* high = stack[top--];
        item* low = stack[top--];

        if (low < high) {
            item* pi = partition(low, high);

            if (pi + 1 < high) {
                stack[++top] = pi + 1;
                stack[++top] = high;
            }

            if (low < pi - 1) {
                stack[++top] = low;
                stack[++top] = pi - 1;
            }
        }
    }

    return true;
}