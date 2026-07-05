fn solution(num: i32) -> i32 {
    if num < 3 {
        return 0;
    }
    let mut multiples: Vec<i32> = Vec::new();
    for k in 3..num {
        if k % 3 == 0 || k % 5 == 0 {
            multiples.push(k);
        }
    }
    multiples.into_iter().sum()
}
