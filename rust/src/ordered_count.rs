use std::collections::HashMap;
// use indexmap::IndexMap;

fn main() {
    let test_str = "i am a master kata solver";
    let ans = ordered_count(test_str);
    for i in ans.iter() {
        println!("{} {}", i.0, i.1);
    }
    // tester(test_str);
}


fn ordered_count(s: &str) -> Vec<(char, i32)> {
    let mut count = HashMap::new();
    let mut ordered = Vec::new();
    for letter in s.chars() {
        let track_count = count.entry(letter).or_insert(0);
        if *track_count == 0 {
            ordered.push(letter);
        }
        *track_count += 1
    }
    ordered.into_iter().map(|letter| (letter, count[&letter])).collect()
}

// this is likely faster but HashMap doesnt preserve
// the order of the letters
// fn ordered_count(s: &str) -> Vec<(char, i32)> {
//     let mut mapped_chars = HashMap::new();
//     for letter in s.chars() {
//         mapped_chars.entry(letter)
//         .and_modify(|letter| *letter += 1)
//         .or_insert(1);
//     }
//     let result: Vec<(char, i32)> = mapped_chars
//         .iter()
//         .map(|(letter, number)| (*letter, *number))
//         .collect();
//     result
// }
//
// this works really well, preserves the order, but
// cant be used on codewars
// fn ordered_count(s: &str) -> Vec<(char, i32)> {
//     let mut mapped_chars = IndexMap::new();
//     for letter in s.chars() {
//         mapped_chars.entry(letter)
//         .and_modify(|letter| *letter += 1)
//         .or_insert(1);
//     }
//     let result:Vec<(char, i32)> = mapped_chars
//         .iter()
//         .map(|(letter, number)| (*letter, *number))
//         .collect();
//     result
// }
//
fn tester(s: &str) {
    let mut result: Vec<(char, i32)> = Vec::new();

    for c in s.chars() {
        println!("{c}");
        result.push((c, 1));
    }
    
    for elem in result.iter() {
        for c in s.chars() {
            if c == elem.0 {
                println!("COWABUNGA");
            }
        }
        println!("{}", elem.0);
    }
}
