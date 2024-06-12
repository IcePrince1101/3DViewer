#!/bin/bash

TELEGRAM_BOT_TOKEN="6727107736:AAFwBMxjzuElToyl96Rm6WjrwwztRAHPJZg"
# raffordg id 584312041
# camillec id 453061728
# pickledl id 388666181

TELEGRAM_USER_ID=("584312041" "453061728" "388666181")
TIME=10
CI_JOB_STARTED_AT=$(date +'%Y-%m-%d %H:%M:%S')
URL="https://api.telegram.org/bot$TELEGRAM_BOT_TOKEN/sendMessage"
TEXT="$GITLAB_USER_NAME has commited to %0Aproject: $CI_PROJECT_NAME %0A%0AMessage: $CI_COMMIT_MESSAGE %0A$CI_JOB_NAME %0Aat $CI_JOB_STARTED_AT %0AStatus: $CI_JOB_STATUS$1%0A%0A%0AURL:+$CI_PROJECT_URL/pipelines/$CI_PIPELINE_ID/%0ABranch:+$CI_COMMIT_REF_SLUG"

for i in ${!TELEGRAM_USER_ID[@]}; do
curl -s --max-time $TIME -d "chat_id=${TELEGRAM_USER_ID[$i]}&disable_web_page_preview=1&text=$TEXT" $URL > /dev/null
done
