let blink = 0;

function clearScreen() {
  console.clear();
}

function drawTree() {
  console.log("\n");
  console.log("           *");
  console.log("          ***");
  console.log("         *****");
  console.log("        *******");
  console.log("       *********");
  console.log("      ***********");
  console.log("     *************");
  console.log("    ***************");
  console.log("   *****************");
  console.log("  *******************");
  console.log("         |||||");
  console.log("         |||||");
  
  // Add blinking ornaments
  if (blink % 2 === 0) {
    console.log("\n       🔴 Lights ON! 🔴");
  } else {
    console.log("\n       ⚪ Lights OFF ⚪");
  }
}

function animate() {
  clearScreen();
  drawTree();
  blink++;
  
  // Stop after 20 blinks (10 seconds)
  if (blink > 20) {
    console.log("\nMerry Christmas! 🎄\n");
    return;
  }
  
  // Continue blinking every 500ms
  setTimeout(animate, 500);
}

// Start the animation
animate();