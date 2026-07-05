// You will be given a list of strings. You must sort it alphabetically 
// (case-sensitive, and based on the ASCII values of the chars) 
// and then return the first value.
//
// The returned value must be a string, and have "***" between each 
// of its letters.
//
// You should not remove or add elements from/to the array.
fn main() {
    let word_array = &["bitcoin", "take", "over", "the", "world", "maybe", "who", "knows", "perhaps"];
    let result = two_sort(word_array);
    println!("{}", result);
}

fn two_sort(arr: &[&str]) -> String {
    let mut words = arr.to_vec();
    words.sort();
    let word = words[0];
    let mut result = String::new();
    for letter in word.chars() {
        result.push_str(&(letter.to_string() + "***"));
    } 
    result.truncate(result.len() - 3);
    result
}


// fn two_sort(arr: &[&str]) -> String {
//     arr.iter()
//         .min()
//         .unwrap()
//         .chars()
//         .map(|c| c.to_string()).collect::<Vec<_>>().join("***")
// }
