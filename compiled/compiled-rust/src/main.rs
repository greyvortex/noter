use std::process::Command;

fn main() {
    println!("🦀 Rust Core: Starting PolyNoteX Engine");

    // Step 1: Call C encryption module
    let input_path = "../compiled-shared/input.txt";
    let encrypted_path = "../compiled-shared/encrypted.txt";

    let _ = Command::new("../compiled-c/encrypt.exe")
        .arg(input_path)
        .arg(encrypted_path)
        .status()
        .expect("Failed to run C encryption");

    println!("🔐 Encryption complete");

    // Step 2: Call C++ search/replace module
    let _ = Command::new("../compiled-cpp/search.exe")
        .arg(encrypted_path)
        .arg("replace_this")
        .arg("with_this")
        .status()
        .expect("Failed to run C++ search");

    println!("🔍 Search/Replace complete");

    // Step 3: Call Java Auth module
    let _ = Command::new("java")
        .arg("-cp")
        .arg("../compiled-java")
        .arg("AuthMain")
        .status()
        .expect("Failed to run Java Auth");

    println!("🔐 Auth complete");

    println!("✅ PolyNoteX Engine finished");
}