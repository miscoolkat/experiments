#!/usr/bin/env node

/**
 * Christmas Tree Generator
 * Creates a festive ASCII Christmas tree in the console
 */

// Configuration
const TREE_HEIGHT = 7; // Number of tree sections
const TRUNK_HEIGHT = 2; // Height of the trunk
const TRUNK_WIDTH = 3;  // Width of the trunk
const STAR = '★';
const TREE_CHAR = '*';
const TRUNK_CHAR = '|';

// ANSI color codes for festive colors
const colors = {
	reset: '\x1b[0m',
	green: '\x1b[32m',
	yellow: '\x1b[33m',
	red: '\x1b[31m',
	brown: '\x1b[33m',
	bright: '\x1b[1m'
};

function printChristmasTree(height = TREE_HEIGHT) {
	const maxWidth = height * 2 + 1;

	// Print the star on top
	const starSpaces = ' '.repeat(Math.floor(maxWidth / 2));
	console.log(starSpaces + colors.yellow + colors.bright + STAR + colors.reset);

	// Print the tree sections
	for (let i = 1; i <= height; i++) {
		const width = i * 2 + 1;
		const spaces = ' '.repeat((maxWidth - width) / 2);
		const treeLine = TREE_CHAR.repeat(width);

		// Add some random decorations (ornaments)
		let decoratedLine = '';
		for (let j = 0; j < treeLine.length; j++) {
			const char = treeLine[j];
			const random = Math.random();

			if (random < 0.1) {
				decoratedLine += colors.red + 'o' + colors.reset; // Red ornaments
			} else if (random < 0.15) {
				decoratedLine += colors.yellow + 'o' + colors.reset; // Yellow ornaments
			} else {
				decoratedLine += colors.green + char + colors.reset; // Green tree
			}
		}

		console.log(spaces + decoratedLine);
	}

	// Print the trunk
	const trunkSpaces = ' '.repeat((maxWidth - TRUNK_WIDTH) / 2);
	const trunk = colors.brown + TRUNK_CHAR.repeat(TRUNK_WIDTH) + colors.reset;

	for (let i = 0; i < TRUNK_HEIGHT; i++) {
		console.log(trunkSpaces + trunk);
	}
}

// Alternative simple version without colors
function printSimpleTree(height = 5) {
	console.log('\n--- Simple Christmas Tree ---');

	// Star
	const maxWidth = height * 2 + 1;
	console.log(' '.repeat(Math.floor(maxWidth / 2)) + '★');

	// Tree
	for (let i = 1; i <= height; i++) {
		const spaces = ' '.repeat(height - i);
		const stars = '*'.repeat(i * 2 - 1);
		console.log(spaces + stars);
	}

	// Trunk
	const trunkSpaces = ' '.repeat(height - 1);
	console.log(trunkSpaces + '|');
	console.log(trunkSpaces + '|');
}

// Animated version
function printAnimatedTree() {
	console.log('\n🎄 Animated Christmas Tree 🎄');
	console.log('Press Ctrl+C to stop the animation\n');

	const frames = [
		{ star: '✦', ornament: 'o' },
		{ star: '✧', ornament: '●' },
		{ star: '★', ornament: 'o' },
		{ star: '☆', ornament: '○' }
	];

	const maxWidth = TREE_HEIGHT * 2 + 1;
	let frameIndex = 0;

	// Listen for any key press to abort
	let interval;
	if (process.stdin.isTTY) {
		process.stdin.setRawMode(true);
		process.stdin.resume();
		process.stdin.on('data', () => {
			clearInterval(interval);
			console.log('\nAnimation stopped by key press. Happy Holidays!');
			process.exit(0);
		});
	}

	// Print frames
	interval = setInterval(() => {
		console.clear();
		const frame = frames[frameIndex % frames.length];

		// Print the animated star
		const starSpaces = ' '.repeat(Math.floor(maxWidth / 2));
		console.log(starSpaces + colors.yellow + colors.bright + frame.star + colors.reset);

		// Print the tree sections with animated ornaments
		for (let i = 1; i <= TREE_HEIGHT; i++) {
			const width = i * 2 + 1;
			const spaces = ' '.repeat((maxWidth - width) / 2);
			let decoratedLine = '';
			for (let j = 0; j < width; j++) {
				const random = Math.random();
				if (random < 0.1) {
					decoratedLine += colors.red + frame.ornament + colors.reset;
				} else if (random < 0.15) {
					decoratedLine += colors.yellow + frame.ornament + colors.reset;
				} else {
					decoratedLine += colors.green + TREE_CHAR + colors.reset;
				}
			}
			console.log(spaces + decoratedLine);
		}

		// Print the trunk
		const trunkSpaces = ' '.repeat((maxWidth - TRUNK_WIDTH) / 2);
		const trunk = colors.brown + TRUNK_CHAR.repeat(TRUNK_WIDTH) + colors.reset;
		for (let i = 0; i < TRUNK_HEIGHT; i++) {
			console.log(trunkSpaces + trunk);
		}

		frameIndex++;
	}, 400);

	// Handle Ctrl+C gracefully
	process.on('SIGINT', () => {
		clearInterval(interval);
		console.log('\nAnimation stopped. Happy Holidays!');
		process.exit(0);
	});
}

// Run the animated tree by default
printAnimatedTree();
