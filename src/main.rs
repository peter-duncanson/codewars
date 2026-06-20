fn main() {
    let m0 = [vec![1, 2], vec![1, 2]];
    let m1 = [vec![1, 2, 3], vec![1, 2, 3], vec![1, 2, 3]];
    let m2 = [vec![1, 2, 3, 4], vec![1, 2, 3, 4], vec![1, 2, 3, 4], vec![1, 2, 3, 4]];
    let m3 = [vec![13, 22, 33], vec![11, 21, 31], vec![12, 22, 31]];
    let t0 = det(&m0);
    let t1 = det(&m1);
    let t2 = det(&m2);
    let t3 = det(&m3);
    println!("{} {} {} {}", t0, t1, t2, t3);
}

fn det(matrix: &[Vec<i64>]) -> i64 {
    let n = matrix.len();
    if n == 2 {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]
    }
    else {
        let mut result: i64 = 0;
        let mut sub: Vec<Vec<i64>> = Vec::with_capacity(n);
        let mut tmp: Vec<i64> = Vec::with_capacity(n);

        for header in 0..n {
            for row in 1..n {
                for col in 0..n {
                    if col != header { tmp.push(matrix[row][col]); }
                }
                sub.push(tmp.clone());
                tmp.clear();
            }
            println!("{:?}", sub);

            if header % 2 == 0 { result += matrix[0][header] * det(&sub) }
            else { result -= matrix[0][header] * det(&sub) }
            
            sub.clear()
        }
        return result;
    }
}
