fn main() {

    let test_matrix = 
    let test_out = determinant(&test_matrix);
    println!("{test_out}");
}

fn determinant(matrix: &[Vec<i128>]) -> i128 {
    let n = matrix.len();
    let mut a: Vec<Vec<i128>> = matrix.to_vec().clone();
    let mut u: Vec<Vec<i128>> = vec![vec![0; n]; n];
    for op in 0..n-1 {
        u = vec![vec![0; n]; n];
        for i in 0..n-op-1 {
            for j in i+1..n {
                if j > i { u[i][j] = a[i][j]; }
                u[i][i] -= a[j][j];
            }
        }
        a = vec![vec![0; n]; n];
        for i in 0..n-op-1 {
            for k in 0..n {
                let factor = u[i][k];
                for j in 0..n { a[i][j] -= factor * matrix[k][j]; }
            }
        }
    }
    a[0][0]
}

