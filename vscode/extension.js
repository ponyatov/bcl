const vscode = require('vscode');

function hello() {
    vscode.window.showInformationMessage('bcl/hello');
}

async function activate(context) {
    vscode.window.showInformationMessage('bcl/activate');
    context.subscriptions.push(
        vscode.commands.registerCommand('dponyatov.bcl.hello', hello)
    );
}

function deactivate() {
    vscode.window.showInformationMessage('bcl/deactivate');
}

module.exports = {
    activate,
    deactivate,
    hello,
};
