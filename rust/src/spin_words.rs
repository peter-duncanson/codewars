fn spin_words(words: &str) -> String {
    let mut result: String = String::new();
    for word in words.split_whitespace() {
        if word.len() >= 5 {
            let rev_word: String = word.chars().rev().collect();
            result.push_str(&rev_word);
        }
        else {
            result.push_str(word);
        }
        result.push(' ');
    }
    result.trim().to_string()
}
