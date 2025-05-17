import express, { Request, Response } from 'express';
import readline from 'readline';

const app = express();
const port = 3000;

app.use(express.json());

let message: string = "1";

const rl = readline.createInterface({
	input: process.stdin,
	output: process.stdout,
});

console.log("Type a new message and press Enter to update the API response");

rl.on('line', (input) => {
	message = input;
	console.log("message has been updated");
});

app.get('/', (req: Request, res: Response) => {
	res.send(message);
});

app.listen(port, () => {
	console.log(`API listening at http://localhost:${port}`);
});

