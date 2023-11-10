#!/bin/bash
set -e

info() { echo -e "\033[0;36m$@\033[0m"; }

info "Syncing with upstream SVN."
git svn fetch --authors-file=debian/authors

info "Splitting sdcc-specific commits."
git checkout git-svn
NEW_HEAD=$(git subtree -P sdcc split)

git switch upstream
OLD_HEAD=$(git rev-parse HEAD)

info "Merging changes into the upstream branch."
revs=$(git log --reverse $OLD_HEAD..$NEW_HEAD --format=%H -- .version)
for rev in $revs; do
    git merge $rev
    V=$(cat .version)
    git tag upstream/$V
    info "Merged version $V."
done
git merge ${NEW_HEAD}

info "Switching back to master."
git switch master
