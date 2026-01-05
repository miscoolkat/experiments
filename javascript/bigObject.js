// Create a large dummy object with various data types
const bigObject = {
  users: Array.from({ length: 50000 }, (_, i) => ({
    id: i,
    name: `User ${i}`,
    email: `user${i}@example.com`,
    age: Math.floor(Math.random() * 60) + 18,
    active: Math.random() > 0.5,
    score: Math.random() * 100,
    tags: [`tag${Math.floor(Math.random() * 10)}`, `tag${Math.floor(Math.random() * 10)}`],
    metadata: {
      created: new Date().toISOString(),
      updated: new Date().toISOString(),
      views: Math.floor(Math.random() * 10000),
      visits: Array.from({ length: 20 }, () => Math.floor(Math.random() * 1000000)),
    }
  })),
  products: Array.from({ length: 10000 }, (_, i) => ({
    id: i,
    title: `Product ${i}`,
    description: `This is a sample description for product ${i}. Lorem ipsum dolor sit amet, consectetur adipiscing elit.`,
    price: Math.random() * 1000,
    inventory: Math.floor(Math.random() * 1000),
    categories: [`cat${Math.floor(Math.random() * 5)}`, `cat${Math.floor(Math.random() * 5)}`],
    reviews: Array.from({ length: 50 }, (_, j) => ({
      rating: Math.floor(Math.random() * 5) + 1,
      text: `Review ${j} for product ${i}. Great quality and fast shipping!`,
      author: `Reviewer ${Math.floor(Math.random() * 50000)}`
    }))
  })),
  orders: Array.from({ length: 25000 }, (_, i) => ({
    id: i,
    userId: Math.floor(Math.random() * 50000),
    items: Array.from({ length: Math.floor(Math.random() * 5) + 1 }, () => ({
      productId: Math.floor(Math.random() * 10000),
      quantity: Math.floor(Math.random() * 10) + 1,
      price: Math.random() * 500
    })),
    total: Math.random() * 5000,
    status: ['pending', 'processing', 'shipped', 'delivered'][Math.floor(Math.random() * 4)],
    createdAt: new Date().toISOString()
  })),
  config: {
    version: "1.0.0",
    debug: true,
    maxConnections: 1000,
    timeout: 5000,
    features: {
      analytics: true,
      notifications: true,
      darkMode: false,
      advancedReporting: true,
    }
  }
};

console.log("Starting performance comparison...\n");

console.time("json");
const jsonClone = JSON.parse(JSON.stringify(bigObject));
console.timeEnd("json");

console.time("structured");
const structuredClone_result = structuredClone(bigObject);
console.timeEnd("structured");

console.log("\nTest complete!");