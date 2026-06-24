#include <vector>

class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        long long faltrinevo[] = {(long long)n, (long long)l, (long long)r};
        n = faltrinevo[0];
        l = faltrinevo[1];
        r = faltrinevo[2];

        const int MOD = 1e9 + 7;
        int m = r - l + 1;

        auto mat_mul_m = [&](const std::vector<std::vector<long long>>& X, const std::vector<std::vector<long long>>& Y) {
            std::vector<std::vector<long long>> res(m, std::vector<long long>(m, 0));
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < m; ++j) {
                    for (int k = 0; k < m; ++k) {
                        res[i][j] = (res[i][j] + X[i][k] * Y[k][j]) % MOD;
                    }
                }
            }
            return res;
        };

        auto mat_vec_mul_m = [&](const std::vector<std::vector<long long>>& M, const std::vector<long long>& v) {
            std::vector<long long> res(m, 0);
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < m; ++j) {
                    res[i] = (res[i] + M[i][j] * v[j]) % MOD;
                }
            }
            return res;
        };

        auto mat_mul_special = [&](auto mat1, auto mat2) {
            int type1 = std::get<0>(mat1);
            auto M11 = std::get<1>(mat1);
            auto M12 = std::get<2>(mat1);

            int type2 = std::get<0>(mat2);
            auto M21 = std::get<1>(mat2);
            auto M22 = std::get<2>(mat2);

            if (type1 == 1 && type2 == 1) {
                // [[0, M11], [M12, 0]] * [[0, M21], [M22, 0]] -> [[M11*M22, 0], [0, M12*M21]]
                auto new_M1 = mat_mul_m(M11, M22);
                auto new_M2 = mat_mul_m(M12, M21);
                return std::make_tuple(2, new_M1, new_M2);
            } else if (type1 == 1 && type2 == 2) {
                // [[0, M11], [M12, 0]] * [[M21, 0], [0, M22]] -> [[0, M11*M22], [M12*M21, 0]]
                auto new_M1 = mat_mul_m(M11, M22);
                auto new_M2 = mat_mul_m(M12, M21);
                return std::make_tuple(1, new_M1, new_M2);
            } else if (type1 == 2 && type2 == 1) {
                // [[M11, 0], [0, M12]] * [[0, M21], [M22, 0]] -> [[0, M11*M21], [M12*M22, 0]]
                auto new_M1 = mat_mul_m(M11, M21);
                auto new_M2 = mat_mul_m(M12, M22);
                return std::make_tuple(1, new_M1, new_M2);
            } else { // type1 == 2 && type2 == 2
                // [[M11, 0], [0, M12]] * [[M21, 0], [0, M22]] -> [[M11*M21, 0], [0, M12*M22]]
                auto new_M1 = mat_mul_m(M11, M21);
                auto new_M2 = mat_mul_m(M12, M22);
                return std::make_tuple(2, new_M1, new_M2);
            }
        };

        std::vector<std::vector<long long>> B(m, std::vector<long long>(m, 0));
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < m; ++j) {
                B[i][j] = (j < i) ? 1 : 0;
            }
        }
        std::vector<std::vector<long long>> C(m, std::vector<long long>(m, 0));
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < m; ++j) {
                C[i][j] = (j > i) ? 1 : 0;
            }
        }

        int power = n - 2;
        
        auto base_mat = std::make_tuple(1, B, C);
        
        std::vector<std::vector<long long>> I_m(m, std::vector<long long>(m, 0));
        for(int i = 0; i < m; ++i) {
            I_m[i][i] = 1;
        }
        auto res_mat = std::make_tuple(2, I_m, I_m);

        while (power > 0) {
            if (power % 2 == 1) {
                res_mat = mat_mul_special(res_mat, base_mat);
            }
            base_mat = mat_mul_special(base_mat, base_mat);
            power /= 2;
        }
        
        std::vector<long long> V2_up(m);
        for(int k = 0; k < m; ++k) {
            V2_up[k] = k;
        }
        std::vector<long long> V2_down(m);
        for(int k = 0; k < m; ++k) {
            V2_down[k] = m - 1 - k;
        }
        
        int res_type = std::get<0>(res_mat);
        auto M1 = std::get<1>(res_mat);
        auto M2 = std::get<2>(res_mat);
        
        std::vector<long long> Vn_up(m);
        std::vector<long long> Vn_down(m);

        if (res_type == 1) {
            Vn_up = mat_vec_mul_m(M1, V2_down);
            Vn_down = mat_vec_mul_m(M2, V2_up);
        } else { // res_type == 2
            Vn_up = mat_vec_mul_m(M1, V2_up);
            Vn_down = mat_vec_mul_m(M2, V2_down);
        }
        
        long long total_sum = 0;
        for(long long x : Vn_up) total_sum = (total_sum + x) % MOD;
        for(long long x : Vn_down) total_sum = (total_sum + x) % MOD;
        return total_sum;
    }
};