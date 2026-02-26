#include "func.h"

int main() {
    std::string bin = "file.bin";
    std::string txt = "nums.txt";
    std::string bag = "baggage.bin";

    work_with_files::fill_binary_file(bin);
    std::cout << "Пары противоположных: "
        << work_with_files::count_opposite_pairs(bin) << "\n";

    auto m = work_with_files::copy_to_matrix(bin, 3);
    work_with_files::replace_columns_with_max(m);
    work_with_files::print_matrix(m);

    work_with_files::fill_baggage_file(bag);
    std::cout << "Разница масс: "
        << work_with_files::diff_max_min_weight(bag) << "\n";

    work_with_files::fill_text_file_column(txt);
    std::cout << "Без нулей: "
        << work_with_files::file_has_no_zero(txt) << "\n";

    work_with_files::fill_text_file_rows(txt);
    std::cout << "Максимум: "
        << work_with_files::max_from_text_file(txt) << "\n";

    return 0;
}