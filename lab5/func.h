#ifndef FUNC_H
#define FUNC_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <algorithm>

class work_with_files {
public:
    // ---------- ЗАДАНИЕ 1 ----------
    static void fill_binary_file(std::string filename);
    static int count_opposite_pairs(std::string filename);

    // ---------- ЗАДАНИЕ 2 ----------
    static std::vector<std::vector<int>> copy_to_matrix(std::string filename, int n);
    static void replace_columns_with_max(std::vector<std::vector<int>>& matrix);
    static void print_matrix(const std::vector<std::vector<int>>& matrix);

    // ---------- ЗАДАНИЕ 3 ----------
    struct Baggage {
        char name[20];
        double weight;
    };

    static void fill_baggage_file(std::string filename);
    static double diff_max_min_weight(std::string filename);

    // ---------- ЗАДАНИЕ 4 ----------
    static void fill_text_file_column(std::string filename);
    static bool file_has_no_zero(std::string filename);

    // ---------- ЗАДАНИЕ 5 ----------
    static void fill_text_file_rows(std::string filename);
    static int max_from_text_file(std::string filename);

    // ---------- ЗАДАНИЕ 6 ----------
    static void copy_lines_by_length(std::string src, std::string dst, int m);
};

#endif