#include "func.h"

// ================= ЗАДАНИЕ 1 =================
void work_with_files::fill_binary_file(std::string filename) {
    std::ofstream file(filename, std::ios::binary);
    srand(time(nullptr));

    int n = rand() % 20 + 10;
    file.write((char*)&n, sizeof(n));

    for (int i = 0; i < n; i++) {
        int x = rand() % 21 - 10;
        file.write((char*)&x, sizeof(x));
    }
    file.close();
}

int work_with_files::count_opposite_pairs(std::string filename) {
    std::ifstream file(filename, std::ios::binary);

    int n;
    file.read((char*)&n, sizeof(n));

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        file.read((char*)&a[i], sizeof(int));

    int count = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] == -a[j])
                count++;

    file.close();
    return count;
}

// ================= ЗАДАНИЕ 2 =================
std::vector<std::vector<int>> work_with_files::copy_to_matrix(std::string filename, int n) {
    std::ifstream file(filename, std::ios::binary);
    int count;
    file.read((char*)&count, sizeof(count));

    std::vector<std::vector<int>> m(n, std::vector<int>(n, 0));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (!file.read((char*)&m[i][j], sizeof(int)))
                m[i][j] = 0;

    file.close();
    return m;
}

void work_with_files::replace_columns_with_max(std::vector<std::vector<int>>& matrix) {
    int n = matrix.size();

    for (int j = 0; j < n; j++) {
        int mx = matrix[0][j];
        for (int i = 1; i < n; i++)
            mx = std::max(mx, matrix[i][j]);

        for (int i = 0; i < n; i++)
            matrix[i][j] = mx;
    }
}

void work_with_files::print_matrix(const std::vector<std::vector<int>>& m) {
    for (auto& row : m) {
        for (int x : row)
            std::cout << x << "\t";
        std::cout << "\n";
    }
}

// ================= ЗАДАНИЕ 3 =================
void work_with_files::fill_baggage_file(std::string filename) {
    std::ofstream file(filename, std::ios::binary);
    srand(time(nullptr));

    int n = rand() % 10 + 5;
    file.write((char*)&n, sizeof(n));

    for (int i = 0; i < n; i++) {
        Baggage b;
        strcpy(b.name, "bag");
        b.weight = rand() % 30 + 1;
        file.write((char*)&b, sizeof(Baggage));
    }
    file.close();
}

double work_with_files::diff_max_min_weight(std::string filename) {
    std::ifstream file(filename, std::ios::binary);

    int n;
    file.read((char*)&n, sizeof(n));

    Baggage b;
    file.read((char*)&b, sizeof(b));
    double minw = b.weight, maxw = b.weight;

    for (int i = 1; i < n; i++) {
        file.read((char*)&b, sizeof(b));
        minw = std::min(minw, b.weight);
        maxw = std::max(maxw, b.weight);
    }

    file.close();
    return maxw - minw;
}

// ================= ЗАДАНИЕ 4 =================
void work_with_files::fill_text_file_column(std::string filename) {
    std::ofstream file(filename);
    srand(time(nullptr));

    for (int i = 0; i < 10; i++)
        file << rand() % 5 << "\n";

    file.close();
}

bool work_with_files::file_has_no_zero(std::string filename) {
    std::ifstream file(filename);
    int x;

    while (file >> x)
        if (x == 0)
            return false;

    return true;
}

// ================= ЗАДАНИЕ 5 =================
void work_with_files::fill_text_file_rows(std::string filename) {
    std::ofstream file(filename);
    srand(time(nullptr));

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++)
            file << rand() % 20 - 10 << " ";
        file << "\n";
    }
    file.close();
}

int work_with_files::max_from_text_file(std::string filename) {
    std::ifstream file(filename);
    int x, mx = -1e9;

    while (file >> x)
        mx = std::max(mx, x);

    return mx;
}

// ================= ЗАДАНИЕ 6 =================
void work_with_files::copy_lines_by_length(std::string src, std::string dst, int m) {
    std::ifstream in(src);
    std::ofstream out(dst);
    std::string s;

    while (getline(in, s))
        if (s.length() == m)
            out << s << "\n";
}