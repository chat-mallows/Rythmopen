# Rythmopen - PoC
> [!CAUTION]
> This branch is **NOT** supposed to be merged.

If you see this README, either you're in the `poc` branch, or we royally fucked up. The goal of this branch is to experiment on our building and development tools, or different ways of coding our application.

The commit norm is not mandatory here, but please try to keep it tidy!

Below, you'll see a non-exhaustive list of the things we discovered and experimented with here.

## Nix
[Nix](https://nixos.org) is a software tool that allows us to approach dependencies in a reproducible and declarative manner. By using flakes, we will provide a developer shell that contains all the packages used to build our application.

### Setup

Please get nix on your system by following [the official instructions](https://nixos.org/download/), or install a downstream distribution such as [determinate nix](https://docs.determinate.systems/determinate-nix/) or [lix](https://lix.systems/).

To load the develop shell:

```sh
nix develop
```

> [!TIP]
> [`direnv`](https://direnv.net/) is a great tool to automatically load the shell when you enters the project directory.
>
> The `direnv` way:
> ```sh
> echo "use flake" | tee .envrc && direnv allow
