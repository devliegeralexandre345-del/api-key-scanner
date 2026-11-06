# API Key Scanner

Scanner CLI de fichiers recherchant des clés d'API et tokens par expressions rationnelles.

## Fonctionnalités

- Analyse récursive des répertoires
- Détection de plusieurs types de clés:
  - AWS Access Key ID
  - Google API Keys
  - Slack Tokens
  - GitHub Personal Access Tokens
  - Stripe API Keys
  - Heroku API Keys
  - Mailgun API Keys
- Support pour les extensions courantes: .txt, .log, .md, .py, .js, .json, .yaml, .yml, .sh, .conf, .cfg, .env

## Compilation

```bash
cmake -B build
cd build && make
```

## Utilisation

```bash
./api_key_scanner /chemin/vers/dossier
```

## Tests

Pour exécuter les tests unitaires:

```bash
cd build && make test
```