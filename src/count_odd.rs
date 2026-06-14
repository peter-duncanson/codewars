n find_odd(arr: &[i32]) -> i32 {
    let mut result: i32 = 0;
    for k in arr {
        let mut c = arr.iter().filter(|&n| *n == *k).count();
        if c % 2 != 0 {
            result = *k;
            break;
        }
    }
    result
}
