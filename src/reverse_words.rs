fn main() {
    let test_string = "The quick brown fox jumped over the lazy dog.";
    let result = reverse_words(test_string);
    println!("{result}");
}

// 10-20% faster by preallocating the vector
// split up words
// let words = str.split(" ");
// let (_, word_count) = words.size_hint();
// initialize vec with capacity
// let mut final_string = Vec::<String>::with_capacity(word_count.unwrap_or(0usize));
// push reversed words to Vec
// words.for_each(|word| final_string.push(word.chars().rev().collect()));
// final_string.join(" ")

// original solution
// fn reverse_words(s: &str) -> String {
//     let mut reversed = String::new();
//     let mut last_space: usize = 0;
//     for (i, &item) in s.as_bytes().iter().enumerate() {
//         if item == b' ' || i + 1 == s.len() {
//             let word: &str = &s[last_space..=i].trim();
//             let reversed_word: String = word.chars().rev().collect();
//             reversed.push_str(&reversed_word);
//             reversed.push(' ');
//             last_space = i;
//         } 
//     }
//     reversed.trim().to_string()
// }

fn reverse_words(s: &str) -> String {
    let words = s.split(" ");
    let (_, word_count) = words.size_hint();
    let mut result = Vec::<String>::with_capacity(word_count.unwrap_or(0usize));
    words.for_each(|word| result.push(word.chars().rev().collect()));
    result.join(" ")
}
