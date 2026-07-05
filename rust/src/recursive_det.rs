fn main() {

    let test_matrix = 
[vec![1, 0, 0, 0, 1, 0, 1, 0, 0, 1],
vec![0, 0, 0, 0, 1, 0, 1, 1, 1, 0],
vec![0, 0, 0, 0, 0, 0, 1, 0, 1, 0],
vec![0, 0, 0, 1, 0, 1, 1, 1, 1, 0],
vec![1, 0, 1, 1, 0, 0, 1, 1, 1, 1],
vec![1, 0, 0, 1, 1, 1, 1, 0, 0, 1],
vec![1, 0, 1, 1, 0, 1, 0, 0, 0, 1],
vec![0, 0, 0, 1, 1, 1, 0, 1, 1, 0],
vec![1, 0, 0, 0, 0, 0, 1, 1, 1, 0],
vec![0, 0, 1, 0, 1, 0, 0, 1, 1, 1]];

    let test_out = det(&test_matrix);
    println!("{test_out}");
}
fn det(matrix: &[Vec<i128>]) -> i128 {
    let n = matrix.len();
    if n == 2 {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]
    }
    else {
        let mut result: i128 = 0;
        let mut sub: Vec<Vec<i128>> = Vec::with_capacity(n);
        let mut tmp: Vec<i128> = Vec::with_capacity(n);

        for header in 0..n {
            for row in 1..n {
                for col in 0..n {
                    if col != header { tmp.push(matrix[row][col]); }
                }
                sub.push(tmp.clone());
                tmp.clear();
            }

            if header % 2 == 0 { result += matrix[0][header] * det(&sub) }
            else { result -= matrix[0][header] * det(&sub) }
            
            sub.clear()
        }
        return result;
    }
}
