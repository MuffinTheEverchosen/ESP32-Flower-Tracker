<%*
const { exec } = require('child_process');

const title = await tp.system.prompt("Tytuł commita i loga");
if (!title) return;

// Czwarty parametr 'true' odpala okno multiline, idealne na dłuższy opis
const content = await tp.system.prompt("Opis postępów", "", false, true);
if (!content) return;

const date = tp.date.now("YYYY-MM-DD");
const logEntry = `\n${date} ${title}\n${content}\n`;

// Zmień nazwę jeśli w przyszłości założysz inny plik
const fileName = "04-log.md";
const file = app.metadataCache.getFirstLinkpathDest(fileName, "");

if (file) {
    await app.vault.append(file, logEntry);
} else {
    new Notice("Nie znaleziono pliku logu!");
    return;
}

const vaultPath = app.vault.adapter.getBasePath();
// Komenda dodaje wszystkie zmiany z vaulta, robi commit z Twoim tytułem i pushuje
const cmd = `cd "${vaultPath}" && git add . && git commit -m "${title}" && git push`;

new Notice("Zapisano log. Wysyłam do repozytorium...");

exec(cmd, (error, stdout, stderr) => {
    if (error) {
        new Notice(`Błąd Git: ${error.message}`);
    } else {
        new Notice(`Sukces: "${title}" wypchnięte pomyślnie!`);
    }
});
%>